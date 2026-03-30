
#include "includes/main.h"

// ADD FORK
int main(void)
{
	t_store	*store;

	if (geteuid() != 0)
	{
		fprintf(stderr, MSG_ROOT);
		return (1);
	}
	printf("LNX launched\n");
	if (!init(&store))
		return (1);
	if (!multi_threading(&store))
		return (1);
	clear_all(&store);
	return (0);
}
