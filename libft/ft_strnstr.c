#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i] && haystack[i] == needle[j] && i < len)
			{
				j++;
				i++;
			}
			if (!needle[j])
				return ((char *)(haystack + i - j));
			i -= j;
		}
		i++;
	}
	return (NULL);
}
