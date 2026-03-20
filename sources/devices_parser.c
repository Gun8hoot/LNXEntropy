
#include "includes/main.h"

t_event	*devices_parser(void)
{
	t_event	*event	= NULL;
	t_event	*cp		= NULL;
	DIR		*dir	= NULL;
	char	*line	= NULL;
	struct dirent *file;
	event = calloc(1, sizeof(t_event));
	if (!event)
		return (NULL);
	dir = opendir("/dev/input/by-path");
	if (dir)
	{
		while ((file = readdir(dir)) != NULL)
		{
			if (strstr(file->d_name, "event-mouse") != 0 || strstr(file->d_name, "event-kbd") != 0)
			{
				if (!event->event_id)
				{
					event->event_id = calloc(1, sizeof(int));
					if (!event->event_id)
						return (NULL);
				}
				else
				{
					cp = realloc(event, event->event_number + 1);
					if (!cp)
						return (NULL);
					event = cp;
				}
				printf("%s\n", file->d_name);
				line = calloc(20 + strlen(file->d_name) + 1, sizeof(char));
				if (!line)
					return (NULL);
				sprintf(line, "/dev/input/by-path/%s", file->d_name);
				event->event_id[event->event_number] = open(line, O_RDONLY | O_NONBLOCK);
				if (!event->event_id[event->event_number])
				{
					if (line)
						free(line);
					closedir(dir);
					return (NULL);
				}
				event->event_number++;
			}
		}
	}


	return (event);
}
