#include "includes/main.h"

void	free_array(void *array)
{
	if (array)
	{
		while (array)
		{
			if (array)
			{
				free(array);
				array = NULL;
			}
			array++;
		}
		free(array);
		array = NULL;
	}
}

void	free_thread(t_store **store)
{
	for (int16_t i = 0; i < (*store)->event.devices_number; i++)
	{
		if ((*store)->thread[i])
		{
			free((*store)->thread[i]);
			(*store)->thread[i] = NULL;
		}
	}
	if ((*store)->thread)
	{
		free((*store)->thread);
		(*store)->thread = NULL;
	}

}

void	clear_event(t_event *event)
{
	for (int i = 0; i < event->devices_number; i++)
	{
		if (event->device_fd[i] > 2)
		{
			close(event->device_fd[i]);
			event->device_fd[i] = -1;
		}
	}
	if (event->device_fd)
	{
		free(event->device_fd);
		event->device_fd = NULL;
	}
}

void	clear_all(t_store **store)
{
	pthread_mutex_destroy(&(*store)->event_lock);
	pthread_mutex_destroy(&(*store)->exit_lock);
	free_thread(store);
	clear_event(&(*store)->event);
	if (*store)
	{
		free(*store);
		*store = NULL;
	}
}
