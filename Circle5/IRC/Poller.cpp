
#include "Poller.hpp"
#include <sys/event.h>

template <typename T>
Poller<T>::Poller(Callback &callback, Socket server) : callback(callback), kqueue(), server(server) {
	KQueue::KEvent	event;

	EV_SET(&event, server.getDescriptor(), EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	this->changes.push_back(event);
}

template <typename T>
void	Poller<T>::addEvent(KQueue::KEvent event) {
	this->changes.push_back(event);
}

template <typename T>
void	Poller<T>::requestWrite(T *client) {
	KQueue::KEvent	event;

	EV_SET(&event, client->getFD(), EVFILT_WRITE, EV_ADD | EV_ENABLE | EV_ONESHOT, 0, 0, client);
	this->changes.push_back(event);
}

template <typename T>
void	Poller<T>::requestClose(T *client) {
	this->close_queue.insert(client);
}

template <typename T>
T	*Poller<T>::accept(void) {
	Socket	client = this->server.accept();
	T*const	data = new T(client, *this);
	KQueue::KEvent	event;

	EV_SET(&event, client.getDescriptor(), EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, data);
	this->changes.push_back(event);
	return (data);
}

template <typename T>
int	Poller<T>::poll(KQueue::KEvent *events, int m) {
	KQueue::KEvent*const	changes = &this->changes[0];
	int const				n = this->changes.size();
	int						count;

	count = this->kqueue.kevent(changes, n, events, m);
	this->changes.clear();
	return (count);
};

template <typename T>
void	Poller<T>::update(void) {
	KQueue::KEvent	events[16];
	int				n;

	n = this->poll(events, 16);
	for (int i = 0; i < n; ++i) {
		KQueue::KEvent	&event = events[i];

		switch (event.filter)
		{
		case EVFILT_READ:
			if (static_cast<int>(event.ident) == this->server.getDescriptor())
				callback.openEventHandler(this->accept());
			else {
				callback.readEventHandler(static_cast<T *>(event.udata), static_cast<int>(event.data));
				if (event.flags & EV_EOF)
					this->requestClose(static_cast<T *>(event.udata));
			}
			break;
		case EVFILT_WRITE:
			callback.writeEventHandler(*this, static_cast<T *>(event.udata), static_cast<int>(event.data));
			break;
		default:
			throw std::runtime_error("Poller<T>::update unhandled EVFILT");
		}
	}
	for (typename std::set<T *>::iterator it = this->close_queue.begin(); it != this->close_queue.end(); ++it) {
		callback.closeEventHandler(*it);
		delete *it;
	}
	this->close_queue.erase(this->close_queue.begin(), this->close_queue.end());
}

