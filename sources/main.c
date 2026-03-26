
#include "includes/main.h"

bool	init(t_store **store)
{
	*store = init_store();
	if (!store)
		return (false);
	if (!devices_parser(&(*store)->event))
		return (false);
	return (true);
}

int main(void)
{
	t_store	*store;

	if (geteuid() != 0)
	{
		printf("[!] Launch the program with the root privileges!\n");
		return (1);
	}
	if (!init(&store))
		return (1);
	return (0);
}
