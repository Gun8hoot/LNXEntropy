
#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "includes/struct.h"

t_event	*devices_parser(t_event *event);
void	free_array(void *array);
void	clear_event(t_event *event);
t_store		*init_store(void);
t_thread	*init_thread(t_store *store);

#endif
