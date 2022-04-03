#include <fdf.h>

t_map	*read_map(char *file_dir)
{
	t_map	*map;
	int		fd;

	map = init_map(file_dir);
	if (!map)
		return (NULL);
	fd = open(file_dir, O_RDONLY);
	if (fd == -1)
	{
		free_map(map->height - 1, map);
		return (NULL);
	}
	if (fill_matrix(map, fd))
	{
		if (close(fd) != -1)
			return (map);
		else
		{
			free_map(map->height - 1, map);
			return (NULL);
		}
	}
	close(fd);
	free_map(map->height - 1, map);
	return (NULL);
}
