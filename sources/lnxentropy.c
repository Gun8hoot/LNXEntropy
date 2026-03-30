#include "includes/main.h"

int	lnxentropy_init()
{
	t_store	*store;
	int		pid;

	if (geteuid() != 0)
	{
		fprintf(stderr, EROOT);
		return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (!init(&store))
			return (1);
		if (!multi_threading(&store))
			return (1);
		for (uint16_t i = 0; i < store->event.devices_number; i++)
			pthread_join(store->thread[i]->tid, NULL);
		return(pid);
	}
	return (pid); // RETURN FORK PID
}

int64_t	lnxentropy_get(uint64_t min, uint64_t max)
{
	;
	return (1); // THE NUMBER GET FROM INPUT
}

bool	lnxentropy_exit(int pid)
{
	kill(pid, SIGQUIT);
	waitpid(pid, NULL, NULL);
	return (1); // STATUS CODE ; 1 SUCCES - 0 FAILURE
}

int	lnxentropy_x11_init()
{
	;
	return (1); // RETURN FORK PID
}

int64_t	lnxentropy_x11_recov()
{
	;
	return (1); // THE NUMBER GET FROM INPUT
}

int	lnxentropy_x11_clean()
{
	return (1); // STATUS CODE ; 1 SUCCES - 0 FAILURE
}
