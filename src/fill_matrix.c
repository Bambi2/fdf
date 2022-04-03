#include <fdf.h>

static int	fill_line(char *str, t_map *map, int j)
{
	char	**row_values;
	int		i;

	row_values = ft_split(str, ' ');
	free(str);
	if (!row_values)
		return (0);
	i = 0;
	while (row_values[i] && row_values[i][0] != '\n')
	{
		map->matrix[j][i] = ft_atoi(row_values[i]);
		i++;
	}
	free_char_matrix(row_values);
	return (1);
}

int	fill_matrix(t_map *map, int fd)
{
	char	*str;
	int		j;

	str = get_next_line(fd);
	if (!str)
		return (0);
	j = 0;
	while (str && str[0] != '\n' && str[0] != ' ')
	{
		if (!fill_line(str, map, j))
			return(0);
		j++;
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	return (1);
}
