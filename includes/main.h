#ifndef MAIN_H
# define MAIN_H

# include "lib/gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <linux/input.h>

typedef struct	s_event
{
	int		*event_id;
	int		event_number;
}				t_event;

t_event	*devices_parser(void);

#endif
