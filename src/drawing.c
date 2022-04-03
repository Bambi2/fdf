#include <fdf.h>

void	put_pixel(t_img *img, t_point point, int color)
{
	char *dst;

	dst = img->addr + (point.x * img->bits_per_pixel / 8) + point.y * img->line_length;
	*(unsigned int *)dst = color;
}

static void	swap_points(t_point *point1, t_point *point2)
{
	t_point	temp;

	temp = *point1;
	*point1 = *point2;
	*point2 = temp;
}

void	draw_line(t_img *img, t_point point1, t_point point2, int color)
{
	float		slope;
	int			rise;
	int			run;
	t_bresenham	bresenham;

	rise = point2.y - point1.y;
	run = point2.x - point1.x;
	slope = rise / run;
	bresenham.offset = 0;
	bresenham.adjust = 1;
	if (slope < 0)
		bresenham.adjust = -1;
	if (slope <= 1 && slope >= -1)
	{
		if (point2.x < point1.x)
			swap_points(&point1, &point2);
		bresenham.delta = abs(rise) / abs(run) * abs(run) * 2;
		bresenham.threshold = 0.5 * 2 * abs(run);
		bresenham.threshold_inc = 2 * abs(run);
		while (point1.x < point2.x)
		{
			put_pixel(img, point1, color);
			point1.x++;
			bresenham.offset += bresenham.delta;
			if (bresenham.offset >= bresenham.threshold)
			{
				point1.y += bresenham.adjust;
				bresenham.threshold += bresenham.threshold_inc;
			}
		}
	}
	else
	{
		if (point2.y < point1.y)
			swap_points(&point1, &point2);
		bresenham.delta = abs(run) / abs(rise) * abs(rise) * 2;
		bresenham.threshold = 0.5 * 2 * abs(rise);
		bresenham.threshold_inc = 2 * abs(rise);
		while (point1.y < point2.y)
		{
			put_pixel(img, point1, color);
			point1.y++;
			bresenham.offset += bresenham.delta;
			if (bresenham.offset >= bresenham.threshold)
			{
				point1.x += bresenham.adjust;
				bresenham.threshold += bresenham.threshold_inc;
			}
		}
	}
}