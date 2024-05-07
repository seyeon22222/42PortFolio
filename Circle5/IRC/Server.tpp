
#include "Server.hpp"
#include <unistd.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <fcntl.h>
#include "KQueue.hpp"

template <typename T>
Server<T>::Server(unsigned short port) {
	int server_socket = ::socket(PF_INET, SOCK_STREAM, 0);
	if (server_socket == -1)
		throw std::runtime_error("Socket::Socket socket creation failed");
	if (::fcntl(server_socket, F_SETFL, O_NONBLOCK) == -1) {
		if (::close(server_socket) == -1)
			throw std::runtime_error("Socket::Socket close failed");
		throw std::runtime_error("Socket::Socket fcntl failed");
	}
	this->socket = Socket(server_socket);
	this->socket.bind("127.0.0.1", port);
	this->socket.listen(5);
}

template <typename T>
void	Server<T>::run(void) {
	Poller<T>	poller(*this, this->socket);

	while (1) {
		poller.update();
	}
}

template <typename T>
void	Server<T>::openEventHandler(T *client) {
	this->onClientConnected(client);
}

template <typename T>
void	Server<T>::closeEventHandler(T *client) {
	this->onClientDisconnected(client);
}

template <typename T>
void	Server<T>::readEventHandler(T *client, int length) {
	int const	fd = client->getFD();
	char*const	buffer = new char[length + 1];

	int n = ::recv(fd, buffer, length, 0);
	if (n == -1) {
		delete[] buffer;
		throw std::runtime_error("socket read failed");
	}
	buffer[n] = '\0';
	this->onReceiveMessage(client, buffer);
	delete[] buffer;
}

template <typename T>
void	Server<T>::writeEventHandler(Poller<T> &poller, T *client, int length) {
	int const			fd = client->getFD();
	unsigned long const	max_length = static_cast<unsigned long>(length);
	std::string const	&full_msg = client->str();
	std::cout << "Send Message : " << full_msg.c_str() << "\n";
	// if (full_msg.size() < max_length) {
		// std::cout << "Send Message : " << full_msg.c_str() << "\n";
		// if (::send(fd, full_msg.c_str(), full_msg.size(), 0) == -1)
		// 	throw std::runtime_error("send failed 0");
		// client->str("");
	// } else {
	// 	std::string const	&to_be_sent = full_msg.substr(0, max_length);
	// 	KQueue::KEvent	kevt;

	// 	EV_SET(&kevt, fd, EVFILT_WRITE, EV_ADD | EV_ENABLE | EV_ONESHOT, 0, 0, NULL);
	// 	this->poller.addEvent(kevt);
	// 	if (::send(fd, to_be_sent.c_str(), to_be_sent.size(), 0) == -1)
	// 		throw std::runtime_error("send failed 1");
	// 	client->str(full_msg.substr(max_length, std::string::npos));
	// }
	if (full_msg.size() < max_length) {
		if (::send(fd, full_msg.c_str(), full_msg.size(), 0) == -1)
			throw std::runtime_error("send failed");
		client->str("");
	} else {
		std::string const	&cut = full_msg.substr(0, max_length);
		if (::send(fd, cut.c_str(), cut.size(), 0) == -1)
			throw std::runtime_error("send failed");
		poller.requestWrite(client);
		client->str(full_msg.substr(max_length));
	}
}
