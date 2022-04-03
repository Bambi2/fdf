#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file	files[OPEN_MAX];
	char			*line;
	char			*temp_line;

	if (fd < 0)
		return (NULL);
	if (files[fd].buf[files[fd].i] == '\0')
		if (!fd_read(fd, files[fd].buf, &files[fd].i))
			return (NULL);
	line = make_line(files[fd].buf, &files[fd].i);
	if (!line)
		return (NULL);
	while (!next_line_check(line))
	{
		if (!fd_read(fd, files[fd].buf, &files[fd].i))
			return (line);
		temp_line = make_line(files[fd].buf, &files[fd].i);
		if (!temp_line)
		{
			free(line);
			return (NULL);
		}
		line = gnl_ft_strjoin(line, temp_line);
	}
	return (line);
}