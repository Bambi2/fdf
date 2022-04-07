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

void	isometric(t_point *point1, t_point *point2, int)
{

}

void	zoom(int zoom, t_point *point1, t_point *point2)
{
	point1->x *= zoom;
	point1->y *= zoom;
	point2->x *= zoom;
	point2->y *= zoom;
}

// int	get_color(int)
// {
// 	int	color;


// 	return(color);
// }
