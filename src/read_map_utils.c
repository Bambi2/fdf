/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:57 by mmalphit          #+#    #+#             */
/*   Updated: 2022/04/08 21:45:12 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	get_width(char *file_dir)
{
	int		fd;
	int		width;
	char	**values;
	char	*temp;

	fd = open(file_dir, O_RDONLY);
	if (fd == -1)
		return (0);
	width = 0;
	temp = get_next_line(fd);
	if (!temp)
		return (0);
	values = ft_split(temp, ' ');
	free(temp);
	if (!values)
		return (0);
	while (values[width] && values[width][0] != '\n')
		width++;
	free_char_matrix(values);
	if (close(fd) == -1)
		return (0);
	return (width);
}

int	get_height(char *file_dir)
{
	int		fd;
	int		height;
	char	*str;

	fd = open(file_dir, O_RDONLY);
	if (fd == -1)
		return (0);
	height = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (str[0] == '\n')
		{
			free(str);
			break ;
		}
		free(str);
		height++;
		str = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (0);
	return (height);
}

int	create_matrix(t_map *map)
{
	int	i;
	int	j;

	map->matrix = (int **) malloc(sizeof(int *) * map->height);
	if (!map->matrix)
	{
		free(map);
		return (0);
	}
	i = 0;
	while (i < map->height)
	{
		map->matrix[i] = (int *) malloc(sizeof(int) * map->width);
		if (!map->matrix[i])
		{
			free_map(i - 1, map);
			return (0);
		}
		j = 0;
		while (j < map->width)
			map->matrix[i][j++] = 0;
		i++;
	}
	return (1);
}

t_map	*init_map(char *file_dir)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = get_height(file_dir);
	if (!(map->height))
	{
		free(map);
		return (NULL);
	}
	map->width = get_width(file_dir);
	if (!(map->width))
	{
		free(map);
		return (NULL);
	}
	if (!create_matrix(map))
		return (NULL);
	return (map);
}
