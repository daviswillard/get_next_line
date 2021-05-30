#include "get_next_line.h"


//#define BUFFER_SIZE 10000

static int	buffer_works(char **line, char **tail, char *buf)
{
	char	*temp;

	if (tail)
	{
		*tail = ft_strchr(buf, '\n');
		*(*tail)++ = '\0';
		*tail = ft_strdup(*tail);
	}
	temp = *line;
	*line = ft_strjoin(*line, buf);
	free(temp);
	return (1);
}

static int	check_tail(char **line, char **tail)
{
	char		*tempest;
	char		*temp;

	if (*tail)
	{
		tempest = ft_strchr(*tail, '\n');
		if (tempest)
		{
			*tempest++ = '\0';
			*line = ft_strdup(*tail);
			temp = *tail;
			*tail = ft_strdup(tempest);
			free(temp);
			return (1);
		}
		*line = ft_strdup(*tail);
		free(*tail);
	}
	else
		*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*tail[1024];
	char			buf[BUFFER_SIZE + 1];
	size_t			bytes;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0))
		return (-1);
	if (check_tail(line, &tail[fd]))
		return (1);
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		if (ft_strchr(buf, '\n') != NULL)
			return (buffer_works(line, &tail[fd], buf));
		(void) buffer_works(line, NULL, buf);
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes < 0)
		return (-1);
	return (0);
}
