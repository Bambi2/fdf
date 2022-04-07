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

void	shift(t_point *point1, t_point *point2, int shift)
{
	point1->x += shift;
	point1->y += shift;
	point2->x += shift;
	point2->y += shift;
}

int	get_color(int z1, int z2)
{
	int	color;

	if (z1 && z2)
		color = 0x00034c3c;
	else if (z1 || z2)
		color = 0x00a6a15e;
	else
		color = 0x00c69f89;
	return (color);
}

