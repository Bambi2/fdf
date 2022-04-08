/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:38 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/08 21:47:45 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	isometric(t_point *point1, t_point *point2, int z1, int z2)
{
	point1->x = (point1->x - point1->y) * cos(0.8);
	point1->y = (point1->x + point1->y) * sin(0.8) - z1;
	point2->x = (point2->x - point2->y) * cos(0.8);
	point2->y = (point2->x + point2->y) * sin(0.8) - z2;
}

void	zoom(int zoom, t_point *point1, t_point *point2)
{
	point1->x *= zoom;
	point1->y *= zoom;
	point2->x *= zoom;
	point2->y *= zoom;
}

void	shift(t_point *point1, t_point *point2, int shift_x, int shift_y)
{
	point1->x += shift_x;
	point1->y += shift_y;
	point2->x += shift_x;
	point2->y += shift_y;
}

int	get_color(int z1, int z2)
{
	int	color;

	if (z1 && z2)
		color = 0x00c3423f;
	else if (z1 || z2)
		color = 0x00d37573;
	else
		color = 0x00fde74c;
	return (color);
}
