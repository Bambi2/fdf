#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		length;
	int		i;
	char	*result;

	length = 0;
	while (s[length])
		length++;
	result = (char *) malloc(length + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[length] = '\0';
	return (result);
}
