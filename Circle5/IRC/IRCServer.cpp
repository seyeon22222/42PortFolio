
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include "IRCServer.hpp"
#include "Util.hpp"
#include "Client.hpp"

IRCServer::IRCChannel::IRCChannel() {
	channelName = "";
	_password = "";
	topic.first = "";
	topic.second = "";
	onlyInvite = false;
	setTopic = false;
	needPassword = false;
	limitUserCnt = false;
	channelUserNum = 0;
}

bool IRCServer::IRCChannel::checkJoinServer(IRCClient *client, IRCChannel &current_channel, std::string param) {
	if ((current_channel.needPassword && current_channel._password != param) || (current_channel.onlyInvite && (current_channel.inviteList.count(client) == 0)) || (current_channel.limitUserCnt && current_channel.channelUserNum < static_cast<int>(current_channel.clientList.size() + 1)))
		return true;
	return false;
}

void	IRCServer::sendAllChannelUser(IRCClient *self, std::string channel, std::string const &message) {
	std::map<std::string, IRCClient *>::iterator it = this->clients.begin();
	for (; it != clients.end(); ++it) {
		if (it->second == self || this->channelList[channel].clientList.count(it->second) == 0)
			continue ;
		*(it->second) << message;
	}
}

void IRCServer::executeKick(IRCClient *client, std::vector<std::string> const &args) {
	std::string channel = args[1];
	std::string user = args[2];
	std::string message = "";
	if (args.size() >= 4)
		message += args[3];

	if (this->channelList.count(channel) == 0)
		throw IRCException(":irc.local 403 " + client->getName() + " " + channel + " :No such channel\r\n");
	if (this->clients.count(user) == 0)
		throw IRCException(":irc.local 401 " + client->getName() + " " + user + " :No suck nick\r\n");
	IRCChannel	&ch = this->channelList[channel];
	if (ch.clientList.count(client) == 0)
		throw IRCException(":irc.local 442 " + client->getName() + " " + channel + " :You're not on that channel!\r\n");
	if (ch.operList.count(client) == 0)
		throw IRCException(":irc.local 482 " + client->getName() + " " + channel + " :You must be a chanel half-operator\r\n");
	std::string reply_msg = ":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " KICK " + channel + " " + user  + " :" + message + "\r\n";
	*client << reply_msg;
	this->sendAllChannelUser(client, channel, reply_msg);
	ch.clientList.erase(this->clients[user]);
	ch.operList.erase(this->clients[user]);
}

// invite nickname channel
void IRCServer::executeInvite(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() != 3)
		throw std::runtime_error("/invite nickname channel");
	std::string user = args[1];
	std::string channel = args[2];

	if (this->clients.count(user) == 0)
		throw IRCException(":irc.local 401 " + client->getName() + " " + user  + " :No such nick\r\n");
	IRCClient	*target = this->clients[user];
	if (this->channelList[channel].operList.count(client) == 0) {
		throw IRCException(":irc.local 482 " + client->getName() + " " + channel + " :You must have channel op access or above to invite\r\n");
	}
	*client << (":irc.local 341 " + client->getName() + " " + user + " :" + channel + "\r\n");
	*target << (":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " INVITE " + user + " :" + channel + "\r\n");
	this->channelList[channel].inviteList.insert(target);
}

// topic channel [topic]
void IRCServer::executeTopic(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() == 2) {
		std::string channel_name = args[1];
		if (this->channelList.count(channel_name) == 0)
			throw IRCException(":irc.local 461 " + client->getName() + " TOPIC : No channel\r\n");
		IRCChannel	&channel = this->channelList[channel_name];
		if (channel.topic.first == "") {
			throw IRCException(":irc.local 331 " + client->getName() + " " + channel_name + " :No topic is set.\r\n");
		}
		*client << (":irc.local 332 " + client->getName() + " " + channel_name + " :" + channel.topic.first +"\r\n");
		*client << (":irc.local 333 " + client->getName() + " " + channel_name + " " + channelList[channel_name].topic.second + "!" + client->getServerIP() + " :1708767448\r\n");
	} else {
		std::string const	&channel_name = args[1];
		std::string const	&topic = args[2];
		IRCChannel	&channel = this->channelList[channel_name];
		if (channel.clientList.count(client) == 0) {
			throw IRCException(":irc.local 442 " + client->getName() + " " + channel_name + " :You're not on that channel!\r\n");
		}
		if (!(channel.setTopic == false || channel.operList.count(client) != 0))
			throw IRCException(":irc.local 482 " + client->getName() + " " + channel_name + " :You do not have access to change the topic on this channel\r\n");
		channel.topic.first = topic;
		channel.topic.second = client->getName();
		std::string reply_msg = ":" + channel.topic.second + "!" + client->getHostName() + "@" + client->getServerIP() + " TOPIC " + channel_name + " :" + topic + "\r\n";
		*client << reply_msg;
		sendAllChannelUser(client, channel_name, reply_msg);
	}
}

///mode <channel> {[+|-]|o|p|s|i|t|n|b|v} [<limit>] [<user>] [<ban mask>]
void IRCServer::executeMode(IRCClient *client, std::vector<std::string> const &args) {
	std::string const	&channel_name = args[1];
	std::string const	&options = args[2];
	bool				active = true;
	size_t				param_idx = 3;

	if (args[1].find("#") == std::string::npos) {
		*client << (":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " MODE " + client->getName() + " :+i\r\n");
		return;
	}
	if (args.size() <= 2) {
		*client << (":irc.local 324 " + client->getName() + " " + channel_name + " :+nt\r\n");
		*client << (":irc.local 329 " + client->getName() + " " + channel_name + " :1709959687\r\n");
		return ;
	}
	if (args[2] == "b") {
		*client << (":irc.local 368 " + client->getName() + " " + channel_name + " :End of channel ban list\r\n");
		return ;
	}
	std::string processed_flags = "";
	std::vector<std::string>	processed_params;
	if (this->channelList[channel_name].clientList.count(client) == 0) {
		throw IRCException(":irc.local 442 " + client->getName() + " " + channel_name + " :You're not on that channel!\r\n");
	}
	if (this->channelList[channel_name].operList.count(client) == 0) {
		throw IRCException(":irc.local 482 " + client->getName() + " " + channel_name + " :You must have channel op access or above to set channel mode\r\n");
	}
	for (std::size_t i = 0; i < options.size(); ++i) {
		switch (options[i])
		{
		case '-':
			active = false;
			break;
		case '+':
			active = true;
			break;
		case 'i':
			this->channelList[channel_name].onlyInvite = active;
			processed_flags += (active ? "+" : "-");
			processed_flags += "i";
			break;
		case 't':
			this->channelList[channel_name].setTopic = active;
			processed_flags += (active ? "+" : "-");
			processed_flags += "t";
			break;
		case 'k':
			if (param_idx >= args.size()) {
				*client << (":irc.local 696 " + client->getName() + " " + channel_name + " k * :You must specify a parameter for the op mode. Syntax: <key>\r\n");
				continue;
			}
			this->channelList[channel_name]._password = args[param_idx];
			this->channelList[channel_name].needPassword = active;
			processed_params.push_back(args[param_idx]);
			param_idx++;
			processed_flags += (active ? "+" : "-");
			processed_flags += "k";
			break;
		case 'o':
			if (param_idx >= args.size()) {
				*client << (":irc.local 696 " + client->getName() + " " + channel_name + " o * :You must specify a parameter for the op mode. Syntax: <nick>\r\n");
				continue;
			}
			if (this->channelList[channel_name].clientList.count(this->clients[args[param_idx]]) == 0) {
				*client << (":irc.local 401 " + client->getName() + " " + args[param_idx] + " :No such nick\r\n");
				continue;
			}
			if (active)
				this->channelList[channel_name].operList.insert(this->clients[args[param_idx]]);
			else
				this->channelList[channel_name].operList.erase(this->clients[args[param_idx]]);
			processed_params.push_back(args[param_idx]);
			param_idx++;
			processed_flags += (active ? "+" : "-");
			processed_flags += "o";
			break;
		case 'l':
			if (active) {
				if (param_idx >= args.size()) {
					*client << (":irc.local 696 " + client->getName() + " " + channel_name + " l * :You must specify a parameter for the op mode. Syntax: <limit>\r\n");
					continue;
				}
				else {
					this->channelList[channel_name].channelUserNum = std::atoi(args[param_idx].c_str());
					processed_params.push_back(args[param_idx]);
					param_idx++;
				}
			}
			this->channelList[channel_name].limitUserCnt = active;
			processed_flags += (active ? "+" : "-");
			processed_flags += "l";
			break;
		}
	}
	std::string reply_msg = ":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " MODE " + channel_name + " " + processed_flags + " ";
	for (size_t i = 0; i < processed_params.size(); ++i) {
		if (i == processed_params.size() - 1)
			reply_msg += ":";
		reply_msg += processed_params[i] + " ";
	}
	reply_msg += "\r\n";
	*client << reply_msg;
	sendAllChannelUser(client, channel_name, reply_msg);
}

// /user <username> <hostname> <servername> <realname>
void IRCServer::executeUser(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() != 5)
		throw IRCException(":irc.local 461 " + client->getName() + " USERHOST : Not enough parameters.\r\n");
	
	std::string const	&hostname = args[2];
	std::string const	&servername = args[3];
	std::string const	&realname = args[4];
	
	
	client->setHostName(hostname);
	client->setServerIP(servername);
	client->setRealName(realname);
	
	*client << (":irc.local 001 " + client->getName() + " :Welcome to the IRC Network " + client->getName() + "!" + client->getRealName() + "@" + client->getServerIP() + "\r\n");
	*client << (":irc.local 002 " + client->getName() + " :Your host is irc.local\r\n");
	*client << (":irc.local 003 " + client->getName() + " :This server was created by " + client->getServerIP() + "\r\n");
	*client << (":irc.local 004 " + client->getName() + " is an imitation of inspircd\r\n");
	*client << (":irc.local 005 " + client->getName() + " PASSLEN=10\r\n");
}

// join <channel>{,<channel>} [<key>{,<key>}]
IRCServer::IRCChannel &IRCServer::fetchChannel(IRCClient *client, std::string channel) {
	if (this->channelList.count(channel) == 0) {
		this->channelList[channel].operList.insert(client);
		this->channelList[channel].clientList.insert(client);
	}
	return (this->channelList[channel]);
}

void IRCServer::executeJoin(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() == 1) {
		throw IRCException(":irc.local 451 * JOIN :You have not registered.\r\n");
	}
	std::vector<std::string> const &channels = Util::split(args[1], ",");
	std::vector<std::string> const &keys = (args.size() <= 2) ? std::vector<std::string>() : Util::split(args[2], ",") ;
	for (size_t idx = 0; idx < channels.size(); ++idx) {
		IRCChannel &current_channel = this->fetchChannel(client, channels[idx]);
		std::string current_key = (idx < keys.size()) ? keys[idx] : "";
		if (current_channel.checkJoinServer(client, current_channel, current_key)) {
			*client << (":irc.local 475 " + client->getName() + " " + channels[idx] + " :Cannot join channel\r\n");
			continue;
		}
		current_channel.clientList.insert(client);
		*client << (":" + client->getName() + "!" +  client->getHostName() + "@" + client->getServerIP() + " JOIN :" + channels[idx] + "\r\n");
		if (current_channel.topic.first != "") {
			*client << (":irc.local 332 " + client->getName() + " " + channels[idx] + " :" + current_channel.topic.first +"\r\n")
			<< (":irc.local 333 " + client->getName() + " " + channels[idx] + " " + current_channel.topic.second + "!" + client->getHostName() + "@" + client->getServerIP() + " :1710218814\r\n");
		}
		*client << (":irc.local 353 " + client->getName() + " = " + channels[idx] + " :");
		std::set<IRCClient *>::iterator it = current_channel.clientList.begin();
		while (true) {
			if (this->channelList[channels[idx]].operList.count(*it))
				*client << "@";
			*client << (*it)->getName();
			++it;
			if (it == current_channel.clientList.end())
				break ;
			*client << " ";
		}
		*client << ("\r\n");
		*client << (":irc.local 366 " + client->getName() + " " + channels[idx] + " :End of /NAMES list.\r\n");
		sendAllChannelUser(client, channels[idx], (":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " JOIN :" + channels[idx] + "\r\n"));
		if (current_channel.inviteList.count(client)) {
			current_channel.inviteList.erase(client);
		}
	}
}

//privmsg <receiver>{,<receiver>} <text to be sent>
void IRCServer::executePrivmsg(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() != 3)
		throw IRCException("bad bad");
	std::vector<std::string>	receiver_name = Util::split(args[1], ",");
	std::string const			&text = args[2];

	for (size_t idx = 0; idx < receiver_name.size(); ++idx) {
		if (receiver_name[idx].find("#") == std::string::npos) {
			std::map<std::string, IRCClient *>::iterator it = this->clients.begin();
			for (; it != clients.end(); ++it) {
				if (it->second->getName() == receiver_name[idx])  {
					*(it->second) << (":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " PRIVMSG " + receiver_name[idx] + " :" + text + "\r\n");
					break ;
				}
			}
			if (it == clients.end()) {
				*client << (":irc.local 401 " + client->getName() + " " + receiver_name[idx] + " :No such nick\r\n");
			}
		}
		else {
			std::map<std::string, IRCChannel>::iterator it = channelList.begin();
			for (; it != channelList.end(); ++it) {
				if (it->first == receiver_name[idx]) {
					std::string reply_msg = ":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " PRIVMSG " + receiver_name[idx] + " :" + text + "\r\n";
					sendAllChannelUser(client, receiver_name[idx], reply_msg);
					break ;
				}
			}
			if (it == channelList.end())
				*client << (":irc.local 403 " + client->getName() + " " + receiver_name[idx] + " :No such channel\r\n");
		}
	}
}

// Quit [<Quit message>]
void IRCServer::executeQuit(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() != 1 && args.size() != 2)
		throw IRCException("bad");
	std::string	quit_msg;

	if (args.size() == 2)
		quit_msg = args[1];
	std::string erase_channel;
	
	while ((erase_channel = this->findChannel(client)) != "") {
		sendAllChannelUser(client, erase_channel, (":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " QUIT :Quit: " + quit_msg + "\r\n"));
		this->channelList[erase_channel].clientList.erase(client);
		if (this->channelList[erase_channel].operList.count(client) != 0)
			this->channelList[erase_channel].operList.erase(client);	
	}
	this->clients.erase(client->getName());
	client->close();
}

// Notice <nickname> <text>
void IRCServer::executeNotice(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() != 3)
		throw IRCException("bad");
	std::string const	&nickname = args[1];
	std::string const	&text = args[2];

	if (this->clients.count(nickname) == 0)
		throw IRCException(":irc.local 401 " + client->getName() + " " + nickname + " :No suck nick\r\n");
	IRCClient	*target = this->clients[nickname];
	*target << (":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " NOTICE " + nickname + " :" + text + "\r\n");
}

// List [<channel>{,<channel>}]
void IRCServer::executeList(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() == 1) {
		*client << (":irc.local 321 a Channel :Users Name\r\n");
		std::map<std::string, IRCChannel>::iterator it = this->channelList.begin();
		for (; it != this->channelList.end(); ++it)
			*client << (":irc.local 322 " + client->getName() + " " + it->first + " " + Util::toString(this->channelList[it->first].clientList.size()) + " :[+n" + (this->channelList[it->first].onlyInvite ? "i" : "") + (this->channelList[it->first].setTopic ? "t" : "") + (this->channelList[it->first].needPassword ? "k" : "") + (this->channelList[it->first].limitUserCnt ? "l" : "") + (this->channelList[it->first].needPassword ? (" " +this->channelList[it->first]._password) : "") + "]\r\n");
		*client << (":irc.local 323 " + client->getName() + " :End of channel list.\r\n");
	}
	else {
		*client << (":irc.local 321 a Channel :Users Name\r\n");
		std::vector<std::string> const	&channel_name = Util::split(args[1], ",");
		for (size_t i = 0; i < channel_name.size(); ++i) {
			if (this->channelList.count(channel_name[i]) == 0)
				continue;
			*client << (":irc.local 322 " + client->getName() + " " + channel_name[i] + " " + Util::toString(this->channelList[channel_name[i]].clientList.size()) + " :[+n" + (this->channelList[channel_name[i]].onlyInvite ? "i" : "") + (this->channelList[channel_name[i]].setTopic ? "t" : "") + (this->channelList[channel_name[i]].needPassword ? "k" : "") + (this->channelList[channel_name[i]].limitUserCnt ? "l" : "") + (this->channelList[channel_name[i]].needPassword ? (" " +this->channelList[channel_name[i]]._password) : "") + "]\r\n");
		}
		*client << (":irc.local 323 " + client->getName() + " :End of channel list.\r\n");
	}
}

// Part <channel>{,<channel>}
void IRCServer::executePart(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() < 2)
		throw IRCException("something wrong");
	std::vector<std::string> const	&channel_name = Util::split(args[1], ",");
	for (size_t i = 0; i < channel_name.size(); ++i) {
		if (this->channelList.count(channel_name[i]) == 0) {
			throw IRCException(":irc.local 403 " + client->getName() + " " + channel_name[i] + " :No such channel\r\n");
		} else if (this->channelList[channel_name[i]].clientList.count(client) == 0){
			throw IRCException(":irc.local 442 " + client->getName() + " " + channel_name[i] + " :You're not on that channel\r\n");
		} else {
			std::string	reply_msg = ":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " PART :" + channel_name[i] + "\r\n";
			*client << reply_msg;
			sendAllChannelUser(client, channel_name[i], reply_msg);
			this->channelList[channel_name[i]].clientList.erase(client);
			this->channelList[channel_name[i]].operList.erase(client);
		}
	}
}

// Ping <server1>
void IRCServer::executePing(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() != 2)
		throw IRCException("Ping Error");
	*client << (":irc.local PONG irc.local :irc.local\r\n");
}

// Pass <password>
void	IRCServer::executePass(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() != 2 || args[1] != this->password) {
		throw IRCPassError("#E");
	}
	(void)client;
}

std::vector<IRCClient *> IRCServer::query(std::string str) {
	std::vector<IRCClient *>	query_clients;
	std::map<std::string, IRCClient *>::iterator it = this->clients.begin();
	
	if (str == "0") {
		for (; it != this->clients.end(); ++it)
			query_clients.push_back(it->second);
	
	} else {
		for (; it != this->clients.end(); ++it) {
			if (Util::wildcard(str, it->second->getName())) {
				query_clients.push_back(it->second);
			}
		}
	}
	return (query_clients);
}

void IRCServer::executeWho(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() < 2)
		throw IRCException("Who Format Error");
	bool		op = (args.size() > 2 && args[2] == "o");

	if (this->channelList.count(args[1])) {
		std::set<IRCClient *>	&set = op ? this->channelList[args[1]].operList : this->channelList[args[1]].clientList;
		std::set<IRCClient *>::iterator it = set.begin();

		for (; it != set.end(); ++it)
			*client << (":irc.local 352 " + args[1] + " " + (*it)->getName() + " " + (*it)->getHostName() + " " + (*it)->getServerIP() + " " + (*it)->getName() + " H" + (this->channelList[args[1]].operList.count(*it) != 0 ? "@ " : " ") + " :0 " + (*it)->getRealName() + "\r\n");
		*client << (":irc.local 315 " + client->getName() + " " + args[1] + " :End of /WHO list.\r\n");	
	} else {
		std::vector<IRCClient *> const &clients = this->query(args[1]);
		for (size_t idx = 0; idx < clients.size(); ++idx) {
			std::string const &clients_channel = this->findChannel(clients[idx]);
			if (clients_channel == "")
				continue;
			std::set<IRCClient *>	&clients_list = op ? this->channelList[clients_channel].operList : this->channelList[clients_channel].clientList;
			if (clients_list.count(clients[idx]))
				*client << (":irc.local 352 " + clients_channel + " " + clients[idx]->getName() + " " + clients[idx]->getHostName() + " " + clients[idx]->getServerIP() + " " + clients[idx]->getName() + " H" + (this->channelList[clients_channel].operList.count(clients[idx]) != 0 ? "@ " : " ") + " :0 " + clients[idx]->getRealName() + "\r\n");
		}
		*client << (":irc.local 315 " + client->getName() + " :End of /WHO list.\r\n");	
	}
}

// Nick <nickname>
void	IRCServer::executeNick(IRCClient *client, std::vector<std::string> const &args) {
	if (args.size() < 2)
		throw IRCException(":irc.local 431 :No nickname given\r\n");
	if (this->clients.count(args[1]) != 0) {
		if (client->getName() == "")
			throw IRCPassError("#E");
		throw IRCException(":irc.local 433 " + client->getName() + " :Nickname is already in use\r\n");
	}
	if (client->getName() == "") {
		client->setName(args[1]);
		this->clients[client->getName()] = client;
		return ;
	}
	std::string reply_msg = ":" + client->getName() + "!" + client->getHostName() + "@" + client->getServerIP() + " NICK :" + args[1] + "\r\n";
	*client << reply_msg;
	std::map<std::string, IRCChannel>::iterator it = this->channelList.begin();
	for (; it != this->channelList.end(); ++it) {
		if (it->second.clientList.count(client) != 0) {
			sendAllChannelUser(client, it->first, reply_msg);
		}
	}
	this->clients.erase(client->getName());
	client->setName(args[1]);
	this->clients[client->getName()] = client;
}


void IRCServer::executeCap(IRCClient *client, std::vector<std::string> const &args) {
	*client << (":irc.local NOTICE * :Connecting....\r\n");
	(void)args;
}

void	IRCServer::execute(IRCClient *client, std::string const &msg) {
	std::vector<std::string>	args = IRC::parseMessage(msg);
	std::string const	&name = args[0];

	try {
		if (name == "KICK")
			executeKick(client, args);
		else if (name == "INVITE")
			executeInvite(client, args);
		else if (name == "TOPIC")
			executeTopic(client, args);
		else if (name == "MODE")
			executeMode(client, args);
		else if (name == "USER" || name == "USERHOST")
			executeUser(client, args);
		else if (name == "JOIN")
			executeJoin(client, args);
		else if (name == "PRIVMSG")
			executePrivmsg(client, args);
		else if (name == "QUIT" || name == "EXIT")
			executeQuit(client, args);
		else if (name == "LIST")
			executeList(client, args);
		else if (name == "NOTICE")
			executeNotice(client, args);
		else if (name == "PART")
			executePart(client, args);
		else if (name == "PING")
			executePing(client, args);
		else if (name == "PASS")
			executePass(client, args);
		else if (name == "NICK")
			executeNick(client, args);
		else if (name == "CAP")
			executeCap(client, args);
		else if (name == "WHO")
			executeWho(client, args);
	} catch (const IRCException &e) {
		*client << e.what();
	}
}