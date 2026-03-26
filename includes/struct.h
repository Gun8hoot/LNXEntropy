
#ifndef STRUCT_H
# define STRUCT_H

#include "includes/includes.h"

typedef struct	s_event
{
	int		*device_fd;		// 8
	int		devices_number;	// 4
}				t_event;

typedef struct	s_thread
{
	int				number;			// 4
	t_event			*event;			// 16
	pthread_mutex_t	*event_lock;	// 40
	pthread_t		*tid;			// 8
	pthread_mutex_t	*exit_lock;		// 40
	bool			*exit;			// 1
}				t_thread;

typedef struct	s_store
{
	t_thread		**thread;		// 40
	t_event			event;			// 16
	pthread_mutex_t	event_lock;		// 40
	pthread_mutex_t	exit_lock;		// 40
	bool			exit;			// 1
	int				test;
}				t_store;

#endif
