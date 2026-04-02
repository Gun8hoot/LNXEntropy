#include "includes/main.h"

int	lnxentropy_init()
{
	t_store	*store;
	int		pid;

	if (geteuid() != 0)
	{
		fprintf(stderr, MSG_ROOT);
		errno = EROOT;
		return (-1);
	}
	if (!get_pipe(true))
	{
		errno = EPIPE_FAILED;
		return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (!init(&store))
			exit(1);
		if (!multi_threading(&store))
			exit(1);
		for (uint16_t i = 0; i < store->event.devices_number; i++)
			pthread_join(store->thread[i]->tid, NULL);
		clear_all(&store);
		exit(0);
	}
	return (pid); // RETURN FORK PID
}

int32_t	lnxentropy_get()
{
	int *pipe_fd = NULL;
	int32_t	get = 0;

	pipe_fd = get_pipe(false);
	read(pipe_fd[1], &get, sizeof(int32_t));
	return (get); // THE NUMBER GET FROM INPUT
}

bool	lnxentropy_exit(int pid)
{
	kill(pid, SIGQUIT);
	waitpid(pid, NULL, 0);
	return (1); // STATUS CODE ; 1 SUCCES - 0 FAILURE
}
