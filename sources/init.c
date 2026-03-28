#include "includes/main.h"

bool	init(t_store **store)
{
	sig_status = 0;
	*store = init_store();
	if (!store)
		return (false);
	if (!devices_parser(&(*store)->event))
		return (false);
	if (!init_signal(&(*store)->sa))
		return (false);
	return (true);
}
