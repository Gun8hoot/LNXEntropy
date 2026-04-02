
#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "includes/struct.h"

t_event	*devices_parser(t_event *event);
void	free_array(void *array);
t_store		*init_store(void);
t_thread	*init_thread(t_store *store);
bool	multi_threading(t_store **store);
bool	init_signal(sa_t	*sig);
void	clear_all(t_store **store);
void	clear_event(t_event *event);
bool	init(t_store **store);
int		lnxentropy_init();
bool	init_pipe(void);
int		*get_pipe(bool pipe_status);

#endif
