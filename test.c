#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>



typedef struct	s_event
{
	int		*device_fd;			// 8 (change to short)
	int		devices_number;		// 4 (change to short)
}				t_event;

typedef struct	s_thread
{
	t_event			*event;			// 40
	pthread_mutex_t	*event_lock;	// 40
	pthread_t		*tid;			// 8
	pthread_mutex_t	*exit_lock;		// 40
	bool			*exit;			// 1
}				t_thread;

int64_t abc(void)
{
	return (12345678910);
}

int main(void)
{
	printf("%ld\n", sizeof(int64_t *));
}
