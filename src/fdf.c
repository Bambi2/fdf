/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:42 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/10 15:21:54 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	fdf(char *file_dir)
{
	t_fdf	fdf;

	fdf = init_fdf(file_dir, 1280, 800);
	if (!fdf.map)
		return (0);
	draw_map(fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
	mlx_hook(fdf.mlx_win, 17, 0, close_window, 0);
	mlx_key_hook(fdf.mlx_win, controlling, &fdf);
	mlx_loop(fdf.mlx);
	free_map(fdf.map->height - 1, fdf.map);
	return (1);
}
