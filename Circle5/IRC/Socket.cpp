
#include "Socket.hpp"
#include <string>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <iostream>
#include <arpa/inet.h>

Socket::Socket() {
	this->fd = -1;
	this->ref_count = NULL;
}

Socket::Socket(int fd) {
	this->fd = fd;
	this->ref_count = new int(1);
}

Socket::Socket(Socket const &other) {
	this->fd = other.fd;
	this->ref_count = other.ref_count;
	if (this->ref_count != NULL)
		*this->ref_count += 1;
}

Socket::~Socket() {
	if (this->ref_count == NULL)
		return ;
	*this->ref_count -= 1;
	if (*this->ref_count == 0) {
		::close(this->fd);
		delete this->ref_count;
	}
}

Socket	&Socket::operator=(Socket other) {
	std::swap(this->fd, other.fd);
	std::swap(this->ref_count, other.ref_count);
	return (*this);
}

void	Socket::bind(std::string const &address, unsigned short port) {
	unsigned int	addr = ::inet_addr(address.c_str());
	sockaddr_in		info;

	info.sin_family = AF_INET;
	info.sin_port = htons(port);
	info.sin_addr.s_addr = addr;
	int	a = 1;
	setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &a, sizeof(a));
	if (::bind(this->fd, reinterpret_cast<sockaddr *>(&info), sizeof(info)) == -1)
		throw std::runtime_error("socket bind fail");
}

void	Socket::listen(int backlog_size) {
	if (::listen(this->fd, backlog_size) == -1)
		throw std::runtime_error("Socket::listen failed");
}

Socket	Socket::accept(void) {
	sockaddr_in	info;
	socklen_t	size = sizeof(info);
	int			sockfd;

	sockfd = ::accept(this->fd,
		reinterpret_cast<sockaddr *>(&info),
		&size);
	if (sockfd == -1)
		throw std::runtime_error("Socket::accept failed");
	if (::fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1)
		throw std::runtime_error("Socket::accept fcntl failed");
	return (Socket(sockfd));
}

// std::string	Socket::read(void) {
// 	std::string	ret;
// 	char		buffer[1024];
// 	int			count;

// 	while (true)
// 	{
// 		switch (count = recv(this->fd, buffer, 1023, 0))
// 		{
// 		case -1:
// 			if (errno == EWOULDBLOCK || errno == EAGAIN)
// 				return (ret);
// 			throw (std::runtime_error("Error while recv"));
// 		case 0:
// 			throw (std::runtime_error("Client socket disconnected while recv"));
// 		default:
// 			buffer[count] = '\0';
// 			ret += buffer;
// 			break;
// 		}
// 	}
// }

// void	Socket::write(std::string const &message) {
// 	::send(this->fd, message.c_str(), message.size(), 0); // #E
// }

bool	Socket::operator==(Socket const &other) const {
	return (this->fd == other.fd);
}
bool	Socket::operator!=(Socket const &other) const {
	return (this->fd != other.fd);
}
bool	Socket::operator<(Socket const &other) const {
	return (this->fd < other.fd);
}
bool	Socket::operator>(Socket const &other) const {
	return (this->fd > other.fd);
}
bool	Socket::operator<=(Socket const &other) const {
	return (this->fd <= other.fd);
}
bool	Socket::operator>=(Socket const &other) const {
	return (this->fd >= other.fd);
}

int	Socket::getDescriptor(void) const {
	return (this->fd);
}
