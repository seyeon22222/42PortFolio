
#ifndef KQUEUE_HPP
# define KQUEUE_HPP

# include <vector>
# include <sys/event.h>

class KQueue {
public:
	typedef struct kevent	KEvent;
	KQueue();
	KQueue(KQueue const &other);
	~KQueue();
	KQueue	&operator=(KQueue other);
	int		kevent(KEvent const *changes, int n, KEvent *events, int m);
private:
	int	fd;
	int	*ref_count;
};

#endif

