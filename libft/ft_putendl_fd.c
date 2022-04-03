#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	newline;

	newline = '\n';
	while (*s)
		write(fd, s++, 1);
	write(fd, &newline, 1);
}
