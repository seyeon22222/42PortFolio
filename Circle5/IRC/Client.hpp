
#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
# include <queue>
# include "Socket.hpp"
# include "Poller.hpp"

template <typename T>
class Client {
public:
	Client(Socket socket, Poller<T> &poller);
	Client	&operator<<(std::string const &msg);
	std::string	str(void) const;
	void	str(std::string const &content);
	int		getFD(void) const;
	void	close(void);
private:
	Poller<T>	&poller;
	std::string	buffer;
	Socket	socket;
	bool		is_valid;
};

# include "Client.cpp"

#endif
