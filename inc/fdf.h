#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <libft.h>
#include <fcntl.h>
#include <math.h>
#include "../get_next_line/get_next_line.h"

typedef struct s_map		t_map;
typedef struct s_img		t_img;
typedef struct s_point		t_point;
typedef struct s_bresenham	t_bresenham;
typedef struct s_fdf		t_fdf;

struct s_map
{
	int	height;
	int	width;
	int	**matrix;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_point
{
	int	x;
	int	y;
};

struct s_bresenham
{
	int		threshold;
	int		threshold_inc;
	int		adjust;
	int		delta;
	int		offset;
	int		rise;
	int		run;
	float	slope;
	t_point point1;
	t_point point2;
};

struct s_fdf
{
	t_map	*map;
	t_img	img;
	void	*mlx;
	void	*mlx_win;
	int		zoom;
};


int	fdf(char *file_dir);

t_map	*read_map(char *file_dir);

//read_map_utils
int		get_width(char *file_dir);
int		get_height(char *file_dir);
int		create_matrix(t_map *map);
t_map	*init_map(char *file_dir);
int		fill_matrix(t_map *map, int fd);

//drawing
void	draw_line(t_fdf fdf, t_point point1, t_point point2);
void	draw_map(t_fdf fdf);

//drawing utils
void	put_pixel(t_img *img, t_point point, int color);
void	swap_points(t_point *point1, t_point *point2);
void	zoom(int zoom, t_point *point1, t_point *point2);

//memory cleaning
void	free_map(int last_row, t_map *map);
void	free_char_matrix(char **matrix);

//common utils
void	swap(int *first, int *second);

#endif