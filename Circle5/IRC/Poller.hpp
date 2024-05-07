
#ifndef POLLER_HPP
# define POLLER_HPP

# include <vector>
# include <set>
# include "Socket.hpp"
# include "KQueue.hpp"


template <typename T>
class Poller {
public:
	class Callback {
	public:
		virtual void	openEventHandler(T *client) = 0;
		virtual void	readEventHandler(T *client, int length) = 0;
		virtual void	writeEventHandler(Poller<T> &poller, T *client, int length) = 0;
		virtual void	closeEventHandler(T *client) = 0;
	};
	Poller(Callback &callback, Socket server);
	void	addEvent(KQueue::KEvent event);
	void	requestWrite(T *client);
	void	requestClose(T *client);
	void	update();
private:
	Poller::Callback	&callback;
	KQueue	kqueue;
	Socket	server;
	std::vector<KQueue::KEvent>	changes;
	std::set<T *>	close_queue;

	int		poll(KQueue::KEvent *events, int m);
	T		*accept();
};

# include "Poller.cpp"

#endif
