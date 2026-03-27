
#include "includes/main.h"

bool	init(t_store **store)
{
	// if (fork() != 0)
	// 	exit(1);
	*store = init_store();
	if (!store)
		return (false);
	if (!devices_parser(&(*store)->event))
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
	if (!init(&store))
		return (1);
	if (!multi_threading(&store))
		return (1);
	return (0);
}
