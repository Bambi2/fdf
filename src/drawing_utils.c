/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:36 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/08 21:45:18 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_pixel(t_img *img, t_point point, int color)
{
	char	*dst;

	dst = img->addr
		+ ((point.x * img->bits_per_pixel / 8)
			+ point.y * img->line_length);
	*(unsigned int *)dst = color;
}

void	swap_points(t_point *point1, t_point *point2)
{
	t_point	temp;

	temp = *point1;
	*point1 = *point2;
	*point2 = temp;
}
