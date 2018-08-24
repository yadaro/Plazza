//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <unistd.h>
#include <stdlib.h>

static char	*get_2(char **line)
{
	char	*tmp = (char *)malloc(sizeof(char) * 1);

	(void)line;
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	return (tmp);
}

static char	*final(char **line, const int i)
{
	(*line)[i] = 0;
	return (*line);
}

char	*get_line(const int fd)
{
	char	buf[2] = "\0";
	char	*line = (char *)malloc(sizeof(char) * 255);
	int	i = 0;
	int	count = 0;

	if (line == NULL)
		return (NULL);
	else if (read(fd, buf, 1) == -1)
		return (NULL);
	else if (buf[0] == '\n')
		return (get_2(&line));
	else if (buf[0] == 0)
		return NULL;
	while (buf[0] != '\n' && buf[0] != '\0') {
		line[i] = buf[0];
		if ((count = read(fd, buf, 1)) == -1)
			return (NULL);
		i++;
		if (count == 0)
			break;
	}
	return (final(&line, i));
}