
#ifndef SOCKET_HPP
# define SOCKET_HPP

# include <string>

class Socket {
public:
	Socket();
	Socket(int descriptor);
	Socket(Socket const &other);
	~Socket();
	Socket	&operator=(Socket other);
	// std::string	read(void);
	// void		write(std::string const &message);
	void		bind(std::string const &address, unsigned short port);
	void		listen(int backlog_size);
	Socket		accept(void);
	bool		operator==(Socket const &other) const;
	bool		operator!=(Socket const &other) const;
	bool		operator<(Socket const &other) const;
	bool		operator>(Socket const &other) const;
	bool		operator<=(Socket const &other) const;
	bool		operator>=(Socket const &other) const;
	int			getDescriptor(void) const;
private:
	int fd;
	int	*ref_count;
};

#endif
