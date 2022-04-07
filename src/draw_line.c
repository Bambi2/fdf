#include <fdf.h>

static void	put_low_line(t_bresenham bresenham, t_img *img, int color)
{
	while (bresenham.point1.x <= bresenham.point2.x)
	{
		put_pixel(img, bresenham.point1, color);
		bresenham.point1.x++;
		bresenham.offset += bresenham.delta;
		if (bresenham.offset >= bresenham.threshold)
		{
			bresenham.point1.y += bresenham.adjust;
			bresenham.threshold += bresenham.threshold_inc;
		}
	}
}

static void	put_high_line(t_bresenham bresenham, t_img *img, int color)
{
	while (bresenham.point1.y <= bresenham.point2.y)
	{
		put_pixel(img, bresenham.point1, color);
		bresenham.point1.y++;
		bresenham.offset += bresenham.delta;
		if (bresenham.offset >= bresenham.threshold)
		{
			bresenham.point1.x += bresenham.adjust;
			bresenham.threshold += bresenham.threshold_inc;
		}
	}
}

static t_bresenham	init_bresenham(t_point point1, t_point point2)
{
	t_bresenham	bresenham;

	bresenham.point1 = point1;
	bresenham.point2 = point2;
	bresenham.rise = bresenham.point2.y - bresenham.point1.y;
	bresenham.run = bresenham.point2.x - bresenham.point1.x;
	bresenham.slope = (float)bresenham.rise / bresenham.run;
	bresenham.offset = 0;
	if (bresenham.slope < 0)
		bresenham.adjust = -1;
	else
		bresenham.adjust = 1;
	if (bresenham.slope >= -1 && bresenham.slope <= 1)
	{
		bresenham.delta = abs(bresenham.rise) * 2;
		bresenham.threshold = abs(bresenham.run);
		bresenham.threshold_inc = abs(bresenham.run) * 2;
	}
	else
	{
		bresenham.delta = abs(bresenham.run) * 2;
		bresenham.threshold = abs(bresenham.rise);
		bresenham.threshold_inc = abs(bresenham.rise) * 2;
	}
	return (bresenham);
}

static void	bresenham_alg(t_img *img, t_point point1, t_point point2, int color)
{
	t_bresenham	bresenham;

	bresenham = init_bresenham(point1, point2);
	if (bresenham.slope >= -1 && bresenham.slope <= 1)
	{
		if (bresenham.point2.x < bresenham.point1.x)
			swap_points(&(bresenham.point1), &(bresenham.point2));
		put_low_line(bresenham, img, color);
	}
	else
	{
		if (bresenham.point2.y < bresenham.point1.y)
			swap_points(&(bresenham.point1), &(bresenham.point2));
		put_high_line(bresenham, img, color);
	}
}

void	draw_line(t_fdf fdf, t_point point1, t_point point2)
{
	int			rise;
	int			run;
	int			color;

	color = get_color(fdf.map->matrix[point1.y][point1.x],
			fdf.map->matrix[point2.y][point2.x]);
	isometric(&point1, &point2, fdf.map->matrix[point1.y][point1.x],
		fdf.map->matrix[point2.y][point2.x]);
	zoom(fdf.zoom, &point1, &point2);
	shift(&point1, &point2, 200);
	rise = point2.y - point1.y;
	run = point2.x - point1.x;
	if (run == 0)
	{
		if (point2.y < point1.y)
			swap_points(&point1, &point2);
		while (point1.y <= point2.y)
		{
			put_pixel(&(fdf.img), point1, color);
			point1.y++;
		}
	}
	else
		bresenham_alg(&(fdf.img), point1, point2, color);
}
