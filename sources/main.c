
#include "includes/main.h"

bool	init(t_store **store)
{
	// if (fork() != 0)
	// 	exit(1);
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
// ADD FORK
int main(void)
{
	t_store	*store;

	if (geteuid() != 0)
	{
		fprintf(stderr, EROOT);
		return (1);
	}
	errno = 27;
	printf("LNX launched\n");
	printf("%d\n", errno);
	if (!init(&store))
		return (1);
	if (!multi_threading(&store))
		return (1);
	clear_all(&store);
	return (0);
}
