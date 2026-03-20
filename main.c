
#include "includes/main.h"

int main(void)
{
	t_event	*event = NULL;
	struct	input_event input;

	if (geteuid() != 0)
	{
		printf("[!] Launch the program with the root privileges!\n");
		return (1);
	}
	event = devices_parser();
	while (1)
	{
		read(event->event_id[0], &input, sizeof(struct input_event));
		if (input.type == EV_ABS)
		{
			printf("Key event: code %d, value %d, type %d\n", input.code, input.value, input.type);
		}
	}
	close(event->event_id[0]);
	// printf("reading fd %d\n\tcode : %d\n\ttype %d\n\tvalue %d\n", event->event_id[1], input.code, input.type, input.value);
	return (0);
}
