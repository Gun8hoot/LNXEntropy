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

void	clear_event(t_event **event)
{
	free_array(&(*event)->device_fd);
	(*event)->devices_number = 0;
}
