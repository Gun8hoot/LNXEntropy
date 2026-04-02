#include "includes/main.h"

int *get_pipe(bool pipe_status)
{
	static int pipe_fd[2];

	if (pipe_status)
	{
		if (!pipe(pipe_fd))
		{
			return (false);
		}
	}
	return (pipe_fd);
}

bool	init_pipe(void)
{
	if (get_pipe(true))
	{
		fprintf(stderr, "[!] Failed to initialized pipe!\n");
		return (false);
	}
	return (true);
}

bool	init(t_store **store)
{
	sig_status = 0;
	*store = init_store();
	if (!store)
		return (false);
	if (!devices_parser(&(*store)->event))
		return (false);
	if (!init_signal(&(*store)->sa))
		return (false);
	return (true);
}
