/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:47 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/08 21:51:00 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_img	init_img(void *mlx, int width, int height)
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

t_fdf	init_fdf(char *file_dir, int size_x, int size_y)
{
	t_fdf	fdf;

	fdf.map = read_map(file_dir);
	if (!fdf.map)
	{
		ft_putstr_fd("Couldn't read the map", 2);
		return (fdf);
	}
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, size_x, size_y, "FDF");
	fdf.img = init_img(fdf.mlx, size_x, size_y);
	if ((size_y / 2 / (fdf.map->height - 1))
		> (size_x / 2 / (fdf.map->width - 1)))
		fdf.zoom = size_y / 2 / (fdf.map->height - 1);
	else
		fdf.zoom = size_x / 2 / (fdf.map->width - 1);
	fdf.shift_x = 450;
	fdf.shift_y = 0;
	return (fdf);
}
