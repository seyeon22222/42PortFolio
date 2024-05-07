
#include "KQueue.hpp"
#include <unistd.h>
#include <netinet/ip.h>
#include <sys/event.h>

KQueue::KQueue() {
	this->fd = ::kqueue();
	this->ref_count = new int(1);
}

KQueue::KQueue(KQueue const &other) {
	this->fd = other.fd;
	this->ref_count = other.ref_count;
	(*this->ref_count)++;
}

KQueue	&KQueue::operator=(KQueue other) {
	std::swap(this->fd, other.fd);
	std::swap(this->ref_count, other.ref_count);
	return (*this);
}

KQueue::~KQueue() {
	(*this->ref_count) -= 1;
	if (*this->ref_count == 0) {
		if (::close(this->fd) == -1)
			throw std::runtime_error("KQueue::~KQueue failed");
		delete ref_count;
	}
}

int	KQueue::kevent(KEvent const *changes, int n, KEvent *events, int m) {
	int const ret = ::kevent(this->fd, changes, n, events, m, NULL);

	if (ret == -1)
		throw std::runtime_error("KQueue::kevent failed");
	return (ret);
}
