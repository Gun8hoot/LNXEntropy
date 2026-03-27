#include "includes/main.h"

bool	check_exit(t_thread *thread)
{
	pthread_mutex_lock(thread->exit_lock);
	if (*thread->exit)
	{
		pthread_mutex_unlock(thread->exit_lock);
		return (true);
	}
	pthread_mutex_unlock(thread->exit_lock);
	return (false);
}

void	*routine(void *ptr_thread)
{
	t_thread	*thread;
	struct	input_event input;

	thread = (t_thread *)ptr_thread;
	while (!check_exit(thread))
	{
		read((*thread->event).device_fd[thread->number], &input, sizeof(struct input_event));
		if (input.type == EV_ABS)
		{
			// if (input.code == EV_SYN)	// POS SUR LE TRACKPAD
			pthread_mutex_lock(thread->event_lock);
			printf("Key event: code %d, value %d, type %d\n", input.code, input.value, input.type);
			pthread_mutex_unlock(thread->event_lock);
		}
		usleep(1000);
	}
	pthread_exit(0);
}

bool	multi_threading(t_store **store)
{
	(*store)->thread = calloc((*store)->event.devices_number, sizeof(t_thread));
	if (!(*store)->thread)
	{
		fprintf(stderr, EALLOC);
		return (false);
	}
	// Create every threads
	for (int i = 0 ; i < (*store)->event.devices_number ; i++)
	{
		(*store)->thread[i] = init_thread(*store);
		pthread_mutex_lock(&(*store)->thread[i]->number_lock);
		(*store)->thread[i]->number = i;
		pthread_mutex_unlock(&(*store)->thread[i]->number_lock);
		if (pthread_create(&(*store)->thread[i]->tid, NULL, &routine, (*store)->thread[i]))
		{
			// If not created, clean everything
			pthread_mutex_lock(&(*store)->exit_lock);
			(*store)->exit = true;
			pthread_mutex_unlock(&(*store)->exit_lock);
			fprintf(stderr, "[!] Failed to create thread!\n");
			break ;
		}
	}

	// Wait until every thread finish
	for (int i = 0 ; i < (*store)->event.devices_number ; i++)
	{
		pthread_join((*store)->thread[i]->tid, NULL);
	}
	return (true);
}

// 1: (*store)->thread = (t_thread **) 0x10000d430
// 2: *(*store)->thread = (t_thread *) 0x10000d4f0
