
#include "includes/main.h"
#include "lib/gnl/get_next_line.h"

int main(void)
{
	FILE	*file = NULL;
	char	*line = NULL;

	// if (geteuid() != 0)
	// {
	// 	printf("[!] Launch the program with the root privileges!\n");
	// 	return (1);
	// }
	file = fopen("/proc/bus/input/devices", "rb");
	if (file == NULL)
	{
		printf("[!] Failed to open devices list file\n");
		return (1);
	}
	while ((line = get_next_line(file)) != NULL)
	{
		printf("%s\n", line);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	fclose(file);
	file = NULL;
	return (0);
}
