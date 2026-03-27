#include "includes/main.h"

void	sigquit_handler()
{
	;
}

bool	init_signal(sa_t	*sig)
{
	sigemptyset(&sig->sa_mask);
	sigaddset(&sig->sa_mask, SIGQUIT);
	sig->sa_flags = SA_SIGINFO;
	sig->sa_sigaction = &sigquit_handler;
	sigaction(SIGQUIT, sig, NULL);
	return (true);
}
