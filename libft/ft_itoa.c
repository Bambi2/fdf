#include "libft.h"

static int	get_length(int n)
{
	int	length;
	int	temp;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	temp = n;
	while (temp != 0)
	{
		length++;
		temp /= 10;
	}
	return (length);
}

static char	*min_value(int n)
{
	char	*result;
	int		length;

	if (n == -2147483648)
	{
		length = 11;
		result = (char *) malloc(length + 1);
		if (!result)
			return (NULL);
		result[length] = '\0';
		n = 2147483647;
		while (n)
		{
			result[length - 1] = n % 10 + 48;
			length--;
			n /= 10;
		}
		result[0] = '-';
		result[10] = '8';
		return (result);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*result;

	result = min_value(n);
	if (result)
		return (result);
	length = get_length(n);
	result = (char *) malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '0';
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	result[length] = '\0';
	while (n)
	{
		result[length - 1] = n % 10 + 48;
		length--;
		n /= 10;
	}
	return (result);
}
