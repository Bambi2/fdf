#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <libft.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

typedef struct s_data	t_data;
typedef struct s_map	t_map;

struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_map
{
	int	height;
	int	width;
	int	**matrix;
};

int	fdf(char *file_dir);

t_map	*read_map(char *file_dir);

//read_map_utils
int		get_width(char *file_dir);
int		get_height(char *file_dir);
int		create_matrix(t_map *map);
t_map	*init_map(char *file_dir);
int		fill_matrix(t_map *map, int fd);

//memory cleaning
void	free_map(int last_row, t_map *map);
void	free_char_matrix(char **matrix);

#endif