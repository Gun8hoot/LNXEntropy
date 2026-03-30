#include "includes/main.h"

t_store		*init_store(void)
{
	t_store	*store;

	store = calloc(1, sizeof(t_store));
	if (!store)
	{
		fprintf(stderr, MSG_ALLOC);
		return (NULL);
	}
	pthread_mutex_init(&store->event_lock, NULL);
	pthread_mutex_init(&store->exit_lock, NULL);
	return (store);
}

t_thread	*init_thread(t_store	*store)
{
	t_thread	*thread;

	thread = calloc(1, sizeof(t_thread));
	if (!thread)
	{
		fprintf(stderr, MSG_ALLOC);
		return (NULL);
	}
	thread->event_lock	= &store->event_lock;
	thread->exit_lock	= &store->exit_lock;
	thread->exit		= &store->exit;
	thread->event		= &store->event;
	pthread_mutex_init(&thread->number_lock, NULL);
	return (thread);
}
