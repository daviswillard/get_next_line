#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"



int	main(void)
{
	int		fd;
	char	*line;
	int		k;

	k = 0;
	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		k++;
		printf("Call: %d\nLine: %s\n", k, line);
		free(line);
	}
	printf("Call: %d\nLine: %s\n", ++k, line);
	free(line);
	close(fd);
	return (0);
}
