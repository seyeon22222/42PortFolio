
#ifndef SERVER_HPP
# define SERVER_HPP

# include <sys/event.h>
# include <string>
# include <map>
# include "Poller.hpp"
# include "Socket.hpp"

template <typename T>
class Server : Poller<T>::Callback {
public:
	Server(unsigned short port);
	void			run(void);
	virtual void	onClientConnected(T *client_id) = 0;
	virtual void	onReceiveMessage(T *client_id, std::string const &msg) = 0;
	virtual void	onClientDisconnected(T *client_id) = 0;
private:
	Socket			socket;

	void	openEventHandler(T *client);
	void	readEventHandler(T *client, int length);
	void	writeEventHandler(Poller<T> &poller, T *client, int length);
	void	closeEventHandler(T *client);
};

# include "Server.tpp"

#endif
