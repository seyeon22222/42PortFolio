
#ifndef IRC_SERVER_HPP
# define IRC_SERVER_HPP

# include <iostream>
# include "Server.hpp"
# include "Client.hpp"
# include "IRCClient.hpp"
# include <map>
# include <set>
# include <list>
# include "IRC.hpp"

class IRCServer : public Server<IRCClient> {
public:
	class IRCChannel {
		public:
			std::string	channelName;
			std::string	_password;
			std::pair<std::string, std::string>	topic;
			std::set<IRCClient *>	operList;
			std::set<IRCClient *>	clientList;
			std::set<IRCClient *>	inviteList;
			bool		onlyInvite;
			bool		setTopic;
			bool		needPassword;
			bool		limitUserCnt;
			int			channelUserNum;
			IRCChannel();
			bool		checkJoinServer(IRCClient *client, IRCChannel &current_channel, std::string param);
	};
	class IRCException : public std::exception {
	public:
		IRCException(std::string msg) : msg(msg) {}
		~IRCException() throw() {}
		const char	*what(void) const throw() {
			return (msg.c_str());
		}
	private:
		std::string msg;
	};
	class IRCPassError : public std::exception {
	public:
		IRCPassError(std::string msg) : msg(msg) {}
		~IRCPassError() throw() {}
		const char	*what(void) const throw() {
			return (msg.c_str());
		}
	private:
		std::string msg;
	};
private:
	std::map<std::string, IRCClient *>	clients;
	std::map<std::string, IRCChannel>	channelList;
	std::string							password;
	bool								passFlag;
	std::string findChannel(IRCClient *client) {
		std::map<std::string, IRCChannel>::iterator it = this->channelList.begin();
		for (; it != this->channelList.end(); ++it) {
			if (it->second.clientList.count(client) != 0)
				return	it->first;
		}
		return "";
	}
	bool	findOperList(IRCClient *client) {
		std::map<std::string, IRCChannel>::iterator it = this->channelList.begin();
		for (; it != this->channelList.end(); ++it) {
			if (it->second.clientList.count(client) != 0){
				if (it->second.operList.count(client) == 0)
					return false;
				else
					return true;
			}
		}
		return false;
	}
public:
	IRCServer(unsigned short port, std::string pass) : Server<IRCClient>(port), password(pass){passFlag = false;}
	void	onClientConnected(IRCClient *client) {
		(void)client;
	};
	void	onReceiveMessage(IRCClient *client, std::string const &msg) {
		int	pos;
		int	count;
		client->buffer += msg;
		if (client->buffer == "LIST \r\n") {
			this->execute(client, client->buffer);
			client->buffer.erase(client->buffer.begin(), client->buffer.end());
			return ;
		}
		while (IRC::message_regex.match(client->buffer, pos, count)) {
			if (pos != 0) {
				client->buffer.erase(0, pos + count);
				throw std::runtime_error("ERROR");
			}
			std::string const	&command = client->buffer.substr(pos, count);
			client->buffer.erase(pos, count);
			try {
				this->execute(client, command);
			} catch (IRCPassError const &e) {
				client->close();
			}
		}
	};
	void	onClientDisconnected(IRCClient *client) {
		std::string erase_channel;
		
		while ((erase_channel = this->findChannel(client)) != "") {
			this->channelList[erase_channel].clientList.erase(client);
			if (this->channelList[erase_channel].operList.count(client) != 0)
				this->channelList[erase_channel].operList.erase(client);
			this->clients.erase(client->getName());
		}
	};

	IRCChannel &fetchChannel(IRCClient *client, std::string channel);
	std::vector<IRCClient *> query(std::string str);
	void	splitMessage(std::string const &message, IRCClient *client);
	void	sendAllChannelUser(IRCClient *self, std::string channel, std::string const &message);
	void	execute(IRCClient *client, std::string const &msg);
	void	executeKick(IRCClient *client, std::vector<std::string> const &args);
	void	executeInvite(IRCClient *client, std::vector<std::string> const &args);
	void	executeTopic(IRCClient *client, std::vector<std::string> const &args);
	void	executeMode(IRCClient *client, std::vector<std::string> const &args);
	void	executeUser(IRCClient *client, std::vector<std::string> const &args);
	void	executeJoin(IRCClient *client, std::vector<std::string> const &args);
	void	executePrivmsg(IRCClient *client, std::vector<std::string> const &args);
	void	executeQuit(IRCClient *client, std::vector<std::string> const &args);
	void	executeList(IRCClient *client, std::vector<std::string> const &args);
	void	executeNotice(IRCClient *client, std::vector<std::string> const &args);
	void	executePart(IRCClient *client, std::vector<std::string> const &args);
	void	executePing(IRCClient *client, std::vector<std::string> const &args);
	void	executePass(IRCClient *client, std::vector<std::string> const &args);
	void	executeNick(IRCClient *client, std::vector<std::string> const &args);
	void	executeCap(IRCClient *client, std::vector<std::string> const &args);
	void	executeWho(IRCClient *client, std::vector<std::string> const &args);
};

#endif
