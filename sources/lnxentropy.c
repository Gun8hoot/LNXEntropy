#include "includes/main.h"

int	lnxentropy_init()
{
	t_store	*store;

	if (geteuid() != 0)
	{
		fprintf(stderr, EROOT);
		return (-1);
	}
	errno = 27;
	if (fork() != 0)
		exit(1);
	if (!init(&store))
		return (1);
	return (1); // RETURN FORK PID
}

int64_t	lnxentropy_recov()
{
	;
	return (1); // THE NUMBER GET FROM INPUT
}

int	lnxentropy_clean()
{
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
