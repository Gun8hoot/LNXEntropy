#include "includes/main.h"

sig_atomic_t	sig_status = 0;

void	sigquit_handler(int signum)
{
	sig_status = signum;
}

bool	init_signal(sa_t	*sig)
{
	sigemptyset(&sig->sa_mask);
	sigaddset(&sig->sa_mask, SIGQUIT);
	sig->sa_flags = SA_SIGINFO;
	sig->sa_handler = &sigquit_handler;
	sigaction(SIGQUIT, sig, NULL);
	return (true);
}
