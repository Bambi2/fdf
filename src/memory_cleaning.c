#include <fdf.h>

void	free_map(int last_row, t_map *map)
{
	while(last_row >= 0)
	{
		free(map->matrix[last_row]);
		last_row--;
	}
	free(map->matrix);
	free(map);
}

void	free_char_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}