#include "includes/main.h"

t_store		*init_store()
{
	t_store	*store;

	store = calloc(1, sizeof(t_store));
	if (!store)
	{
		fprintf(stderr, "[!] Failled to allocated memory\n");
		return (NULL);
	}
	store->thread = NULL;
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
		fprintf(stderr, "[!] Failled to allocated memory\n");
		return (NULL);
	}
	thread->event_lock	= &store->event_lock;
	thread->exit_lock	= &store->exit_lock;
	thread->exit		= &store->exit;
	return (thread);
}
