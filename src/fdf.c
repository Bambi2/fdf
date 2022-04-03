#include <fdf.h>

int	fdf(char *file_dir)
{
	t_map	*map;

	map = read_map(file_dir);
	if (!map)
	{
		ft_putstr_fd("Couldn't read the map", 2);
		return (0);
	}
	free_map(map->height - 1, map);
	return (1);
}