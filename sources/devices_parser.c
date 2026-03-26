
#include "includes/main.h"

int	init_device(t_event *event, char *filename)
{
	int	*cp		= NULL;
	char	*line	= NULL;

	if (!event->device_fd)
	{
		event->device_fd = calloc(1, sizeof(int));
		if (!event->device_fd)
			return (-1);
	}
	else
	{
		cp = realloc(event->device_fd, sizeof(int) * (event->devices_number + 1));
		if (!cp)
		{
			fprintf(stderr, "[!] Failed to allocate memory!\n");
			return (-1);
		}
		event->device_fd = cp;
	}
	line = calloc(BY_PATH_STR_SIZE + strlen(filename) + 1, sizeof(char));
	if (!line)
		return (-1);
	sprintf(line, "/dev/input/by-path/%s", filename);
	event->device_fd[event->devices_number] = open(line, O_RDONLY | O_NONBLOCK);
	if (!event->device_fd[event->devices_number])
	{
		if (line)
			free(line);
		return (-1);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (event->device_fd[event->devices_number]);
}

t_event	*devices_parser(t_event *event)
{
	DIR		*dir	= NULL;
	struct	dirent *file;

	dir = opendir("/dev/input/by-path");
	if (!dir)
	{
		fprintf(stderr, "[!] Failed to open /dev/input/by-path\n");
		return (NULL);
	}
	while ((file = readdir(dir)) != NULL)
	{
		if (strstr(file->d_name, "event-mouse") != 0 || strstr(file->d_name, "event-kbd") != 0)
		{
			if (init_device(event, file->d_name) < 0)
			{
				clear_event(event);
				closedir(dir);
				return (NULL);
			}
			event->devices_number++;
		}
	}
	return (event);
}
