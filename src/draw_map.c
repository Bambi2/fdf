/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:33 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/08 21:46:09 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_map(t_fdf fdf)
{
	t_point	point1;
	t_point	point2;

	point1.y = 0;
	point2.y = 1;
	while (point1.y < fdf.map->height)
	{
		point1.x = 0;
		point2.x = 0;
		while (point1.x < fdf.map->width)
		{
			if (point1.y != (fdf.map->height - 1))
				draw_line(fdf, point1, point2);
			point2.x++;
			point2.y--;
			if (point1.x != (fdf.map->width - 1))
				draw_line(fdf, point1, point2);
			point2.y++;
			point1.x++;
		}
		point1.y++;
		point2.y++;
	}
}
