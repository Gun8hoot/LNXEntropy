
#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "includes/struct.h"

t_event	*devices_parser(void);
void	free_array(void *array);
void	clear_event(t_event **event);

#endif
