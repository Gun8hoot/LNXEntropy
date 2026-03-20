#ifndef MAIN_H
# define MAIN_H

# include "lib/gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <linux/input.h>
# include <linux/input-event-codes.h>
# include <dirent.h>

typedef struct	s_event
{
	int		*event_id;
	int		event_number;
}				t_event;

typedef struct	s_thread
{
	pthread_mutex_t	value_lock;
	pthread_mutex_t	end_lock;
	pthread_t		*tid;
}				t_thread;

t_event	*devices_parser(void);

#endif
