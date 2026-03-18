
#include "includes/main.h"
#include "lib/gnl/get_next_line.h"
#include <stdlib.h>
#include <string.h>

t_event	*devices_parser(void)
{
	t_event	*event	= NULL;
	FILE	*file	= NULL;
	char	*line	= NULL;
	char	*store	= NULL;

	file = fopen("/proc/bus/input/devices", "rb");
	if (file == NULL)
	{
		printf("[!] Failed to open devices list file\n");
		return (NULL);
	}
	event = calloc(1, sizeof(t_event));
	if (!event)
	{
		printf("[!] Failed to allocated memory!\n");
		return (NULL);
	}
	event->event_id = calloc(1, sizeof(int));
	if (!event->event_id)
	{
		printf("[!] Failed to allocated memory!\n");
		return (NULL);
	}
	while ((line = get_next_line(file)) != NULL)
	{
		if (line[0] == 'N')
		{
			if (strstr(line, "Touchpad") || strstr(line, "Mouse") || strstr(line, "keyboard"))
			{
				while (line && line[0] != 'H')
					line = get_next_line(file);
				line = strstr(line, "event");
				line += 5;
				while (line && *line != ' ' && *line != '\n')
				{
					if (!store)
						store = calloc(1, sizeof(char));
					// ADD REALLOC
					if (!store)
					{
						fprintf(stderr, "[!] Failed to allocated memory!\n");
						return (NULL);
					}
					*store = *line;
					store++;
					*store = '\0';
					line++;
				}
				event->event_id[event->event_number++] = atoi(store);
				if (store)
					free(store);
			}
		}
		if (line)
			free(line);
	}
	return (event);
}
