
#include "includes/main.h"

int main(void)
{
	t_store	*store = NULL;

	if (geteuid() != 0)
	{
		printf("[!] Launch the program with the root privileges!\n");
		return (1);
	}
	store->event = devices_parser();
	if (!store->event)
		return (1);
	return (0);
}
