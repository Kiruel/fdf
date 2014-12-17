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

int		*ft_count_line(char **av)
{
	int 	fd;
	char 	*line;
	int 	*height;
	char 	**map_char;

	height = (int*)ft_memalloc(sizeof(int) * 2);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("opent() failed\n", 2);
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		map_char = ft_strsplit(line, ' ');
		while (map_char[height[0]])
			height[0]++;
		height[1]++;
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (0);
	}
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

	line = NULL;
	height = ft_count_line(av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("opent() failed\n", 2);
		return (NULL);
	}
	list = NULL;
	list = (t_data***)ft_memalloc(sizeof(t_data**) * height[1]);
	coor_x = 0;
	while (get_next_line(fd, &line) > 0)
	{	
		map_char = ft_strsplit(line, ' ');
		coor_y = 0;
		list[coor_x] = (t_data**)ft_memalloc(sizeof(t_data*) * height[0]);
		while (map_char[coor_y])
		{
			list[coor_x][coor_y] = (t_data*)ft_memalloc(sizeof(t_data));
			list[coor_x][coor_y]->x = coor_x;
			list[coor_x][coor_y]->y = coor_y;
			list[coor_x][coor_y]->z = ft_atoi(map_char[coor_y]);
			coor_y++;
		}
		coor_x++;
	}
	map_char = ft_strsplit(line, ' ');
	coor_y = 0;
	list[coor_x] = (t_data**)ft_memalloc(sizeof(t_data*) * height[0]);
	while (map_char[coor_y])
	{
		list[coor_x][coor_y] = (t_data*)ft_memalloc(sizeof(t_data));
		list[coor_x][coor_y]->x = coor_x;
		list[coor_x][coor_y]->y = coor_y;
		list[coor_x][coor_y]->z = ft_atoi(map_char[coor_y]);
		coor_y++;
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (NULL);
	}
	return (list);
}
