
#include "includes/main.h"

int main(void)
{
	t_event	*event = NULL;


	// if (geteuid() != 0)
	// {
	// 	printf("[!] Launch the program with the root privileges!\n");
	// 	return (1);
	// }
	event = devices_parser();
	for (int i = 0; i < event->event_number; i++)
	{
		printf("event%d\n", event->event_id[i]);
	}
	return (0);
}
