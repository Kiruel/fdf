/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:39:09 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/16 11:39:10 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*void			ft_get_center(t_result *ret)
{
	int					x;

	x = 0;
	while (ret->map[0][x])
		x++;
	x--;
	while (!ret->map[ret->size])
		ret->size--;
	ret->delta_x = (ret->map[ret->size][x]->x + ret->map[0][0]->x) / 2;
	ret->delta_y = (ret->map[ret->size][x]->y + ret->map[0][0]->y) / 2;
	ret->delta_z = (ret->map[ret->size][x]->z + ret->map[0][0]->z) / 2;
}*/

static int		ft_map_width(char **value)
{
	int		i;

	i = 0;
	while (value[i])
		i++;
	return (i);
}

static t_data	**ft_add_entry(char *buf, int y)
{
	t_data		**line;
	int			i;
	int			x;
	int			width;
	char		**value;

	value = ft_strsplit(buf, ' ');
	i = ft_map_width(value);
	x = -1;
	width = 0;
	if ((line = (t_data**)ft_memalloc(sizeof(t_data*) * i + 1)) == NULL)
	{
		ft_putendl_fd("malloc error", 2);
		exit(2);
	}
	while (++x < i)
	{
		if ((line[x] = (t_data*)ft_memalloc(sizeof(t_data))) == NULL)
			ft_mallerr();
		line[x]->z = ft_atoi(value[x]);
		line[x]->x = width;
		line[x]->y = y;
		line[x]->s = 1;
		free(value[x]);
		width++;
	}
	free(value);
	return (i ? line : NULL);
}

static int		ft_map_height(char *file)
{
	int		height;
	int		fd;
	int		rt;
	char	*buf;

	height = 0;
	fd = ft_open(file);
	while ((rt = get_next_line(fd, &buf)) > 0)
	{
		height++;
		free(buf);
	}
	if (rt == -1)
		ft_error("gnl");
	ft_close(fd);
	return (height);
}

void			ft_read_data(char *file, t_env *ret)
{
	int					fd;
	char				*buf;
	int					rt;
	int					size;
	int					height;

	height = 0;
	size = ft_map_height(file);
	if ((ret->map = (t_data***)ft_memalloc(sizeof(t_data**)
	* (size + 1))) == NULL)
		ft_mallerr();
	fd = ft_open(file);
	while ((rt = get_next_line(fd, &buf)) > 0)
	{
		ret->map[ret->size] = ft_add_entry(buf, height);
		// ft_rgb(ret->map[ret->size]);
		// free(buf);
		ret->size++;
		height++;
	}
	if (rt == -1)
		ft_error("gnl");
}

/*#include "includes/fdf.h"

int		*ft_count_line(char **av)
{
	int 	fd;
	char 	*line;
	int 	*height;
	char 	**map_char;
	int 	long_y;
	int		p;
	int 	i;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("opent() failed\n", 2);
	}
	long_y = 0;
	while (get_next_line(fd, &line) > 0)
		long_y++;
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("opent() failed\n", 2);
	}
	p = 1;
	height = (int*)ft_memalloc(sizeof(int) * long_y + 1);
	while (get_next_line(fd, &line) > 0)
	{
		map_char = ft_strsplit_fdf(line);
		i = 0;
		while (map_char[i])
		{
			height[p]++;
			i++;
		}
		height[0]++;
		p++;
	}
	i = 0;
	map_char = ft_strsplit_fdf(line);
	while (map_char[i])
	{
		height[p]++;
		i++;
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (0);
	}
	height[0]++;
	return (height);
}

t_data		***ft_read_data(char **av)

{
	t_data 	***list;
	char 	*line;
	char 	**map_char;
	int 	fd;
	int 	coor_x;
	int		coor_y;
	int 	*height;
	int		long_x;

	line = NULL;
	height = ft_count_line(av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("opent() failed\n", 2);
		return (NULL);
	}
	list = NULL;
	list = (t_data***)ft_memalloc(sizeof(t_data**) * height[0]);
	coor_x = 0;
	long_x = 1;
	while (height[coor_x + 1])
	{
		ft_putnbr(height[coor_x + 1]);
		ft_putchar('\n');
		coor_x++;
	}
	coor_x = 0;
	while (get_next_line(fd, &line) > 0)
	{	
		map_char = ft_strsplit_fdf(line);
		coor_y = 0;
		list[coor_x] = (t_data**)ft_memalloc(sizeof(t_data*) * height[long_x]);
		while (map_char[coor_y])
		{
			list[coor_x][coor_y] = (t_data*)ft_memalloc(sizeof(t_data));
			list[coor_x][coor_y]->x = coor_y;
			list[coor_x][coor_y]->y = coor_x;
			list[coor_x][coor_y]->z = ft_atoi(map_char[coor_y]);
			coor_y++;
		}
		long_x++;
		coor_x++;
	}
	map_char = ft_strsplit_fdf(line);
	coor_y = 0;
	list[coor_x] = (t_data**)ft_memalloc(sizeof(t_data*) * height[long_x]);
	while (map_char[coor_y])
	{
		list[coor_x][coor_y] = (t_data*)ft_memalloc(sizeof(t_data));
		list[coor_x][coor_y]->x = coor_y;
		list[coor_x][coor_y]->y = coor_x;
		list[coor_x][coor_y]->z = ft_atoi(map_char[coor_y]);
		coor_y++;
	}
	free(height);
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (NULL);
	}
	return (list);
}*/
