/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:26 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/09 13:13:34 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	shifting(int key, t_fdf *fdf)
{
	if (key == UP)
		fdf->shift_y -= 10;
	else if (key == LEFT)
		fdf->shift_x -= 10;
	else if (key == DOWN)
		fdf->shift_y += 10;
	else if (key == RIGHT)
		fdf->shift_x += 10;
}

static void	zooming(int key, t_fdf *fdf)
{
	if (key == ZOOM_IN)
	{
		if ((fdf->zoom * (fdf->map->height - 1)) < 800
			&& (fdf->zoom * (fdf->map->width - 1)) < 1280)
				fdf->zoom += 1;
	}
	else if (key == ZOOM_OUT)
	{
		if (fdf->zoom > 0)
			fdf->zoom -= 1;
	}
}

int	close_window(int key)
{
	ft_putnbr_fd(key, 1);
	exit(EXIT_SUCCESS);
	return (0);
}

int	controlling(int key, t_fdf *fdf)
{
	ft_putnbr_fd(key, 1);
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if ((key <= RIGHT && key >= LEFT) || key == UP)
		shifting(key, fdf);
	else if (key == ZOOM_IN || key == ZOOM_OUT)
		zooming(key, fdf);
	else
		return (0);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img = init_img(fdf->mlx, 1280, 800);
	draw_map(*fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}
