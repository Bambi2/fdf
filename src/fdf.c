#include <fdf.h>

static t_img	init_img(void *mlx, int width, int height)
{
	t_img	img;

	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(
			img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian);
	return (img);
}

int	fdf(char *file_dir)
{
	t_fdf	fdf;

	fdf.map = read_map(file_dir);
	if (!fdf.map)
	{
		ft_putstr_fd("Couldn't read the map", 2);
		return (0);
	}
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, 1920, 1080, "FDF");
	fdf.img = init_img(fdf.mlx, 1920, 1080);
	fdf.zoom = 20;
	draw_map(fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
	mlx_loop(fdf.mlx);
	free_map(fdf.map->height - 1, fdf.map);
	return (1);
}
