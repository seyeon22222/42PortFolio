
#ifndef IRC_CLIENT_HPP
# define IRC_CLIENT_HPP

# include "Client.hpp"
# include <iostream>
# include <list>

class IRCClient : public Client<IRCClient> {
public:
	IRCClient(Socket socket, Poller<IRCClient> &poller) : Client(socket, poller) {
		name = "";
		command = "";
		params = "";
		clientUserName = "";
		clientHostName = "";
		clientServerIP = "";
		clientRealName = "";
		flag = false;
		canInvite = false;
	}
	std::string getName() const {return name;}
	std::string getCmd() const {return command;}
	std::string getParams() const {return params;}
	std::string getUserName() const {return clientUserName;}
	std::string getHostName() const {return clientHostName;}
	std::string getServerIP() const {return clientServerIP;}
	std::string getRealName() const {return clientRealName;}
	std::list<std::string> getChannel() const {return inChannel;}
	bool getFlag() const {return flag;}
	bool getInvite() const {return canInvite;}
	void setName(std::string str) {name = str;}
	void setCmd(std::string str) {command = str;}
	void setParams(std::string str) {params = str;}
	void setUserName(std::string str) {clientUserName = str;}
	void setHostName(std::string str) {clientHostName = str;}
	void setServerIP(std::string str) {clientServerIP = str;}
	void setRealName(std::string str) {clientRealName = str;}
	void setChannel(std::string str) {inChannel.push_back(str);}
	void setChannel(std::list<std::string> v) {inChannel = v;}
	void popChannel(std::list<std::string>::iterator it) {inChannel.erase(it);}
	void setFlag(bool _flag) {flag = _flag;}
	void setInvite(bool _flag) {canInvite = _flag;}
	
	std::string	buffer;
private:
	std::string name;
	std::string	command;
	std::string	params;
	std::string clientUserName;
	std::string clientHostName;
	std::string clientServerIP;
	std::string clientRealName;
	std::list<std::string> inChannel;

	bool		flag;
	bool		canInvite;
};

#endif