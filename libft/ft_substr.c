#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	while (s[i + start] && i < len && start < ft_strlen(s))
		i++;
	result = (char *) malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] && start < ft_strlen(s))
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}
