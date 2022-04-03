#include <fdf.h>

t_img	init_img(void *mlx, int width, int height)
{
	t_img	img;

	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(&img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

int	fdf(char *file_dir)
{
	t_map	*map;
	t_img	img;
	void	*mlx;

	map = read_map(file_dir);
	if (!map)
	{
		ft_putstr_fd("Couldn't read the map", 2);
		return (0);
	}
	mlx = mlx_init();
	img = init_img(mlx, 1920, 1080);
	free_map(map->height - 1, map);
	return (1);
}