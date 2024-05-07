
#include "Client.hpp"
#include "KQueue.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <sys/event.h>

template <typename T>
Client<T>::Client(Socket socket, Poller<T> &poller) : poller(poller), socket(socket), is_valid(true) {
	KQueue::KEvent	kevt;

	EV_SET(&kevt, this->socket.getDescriptor(), EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, this);
	this->poller.addEvent(kevt);
}

template <typename T>
Client<T>	&Client<T>::operator<<(std::string const &msg) {
	if (!this->is_valid)
		return (*this);
	this->buffer += msg;
	this->poller.requestWrite(static_cast<T *>(this));
	return (*this);
}

template <typename T>
std::string	Client<T>::str(void) const {
	if (!this->is_valid)
		return ("");
	return (this->buffer);
}

template <typename T>
void	Client<T>::str(std::string const &content) {
	if (!this->is_valid)
		return ;
	this->buffer = content;
}

template <typename T>
int	Client<T>::getFD(void) const {
	return (this->socket.getDescriptor());
}

template <typename T>
void	Client<T>::close(void) {
	if (!this->is_valid)
		return ;
	this->is_valid = false;
	poller.requestClose(reinterpret_cast<T *>(this));
}
