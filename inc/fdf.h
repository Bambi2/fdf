/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:11:00 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/10 15:11:01 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include <fcntl.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"

# define ESC		53
# define UP			13
# define LEFT		0
# define RIGHT		2
# define DOWN		1
# define ZOOM_IN	24
# define ZOOM_OUT	27

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
	t_point	point1;
	t_point	point2;
};

struct s_fdf
{
	t_map	*map;
	t_img	img;
	void	*mlx;
	void	*mlx_win;
	int		zoom;
	int		shift_x;
	int		shift_y;
};

int		fdf(char *file_dir);

t_map	*read_map(char *file_dir);

//init fdf
t_img	init_img(void *mlx, int width, int height);
t_fdf	init_fdf(char *file_dir, int size_x, int size_y);

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

//controlling
int		controlling(int key, t_fdf *fdf);
int		close_window(int key);

//editing
void	zoom(int zoom, t_point *point1, t_point *point2);
void	isometric(t_point *point1, t_point *point2, int z1, int z2);
void	shift(t_point *point1, t_point *point2, int shift_x, int shift_y);
int		get_color(int z1, int z2);

//memory cleaning
void	free_map(int last_row, t_map *map);
void	free_char_matrix(char **matrix);

//common utils
void	swap(int *first, int *second);

#endif