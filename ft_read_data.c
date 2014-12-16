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

t_data		***ft_read_data(char **av)

{
	t_data 	***list;
	char 	*line;
	char 	**coor_z;
	int 	fd;
	int 	coor_x;
	int		j;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("opent() failed\n", 2);
		return (NULL);
	}
	list = NULL;
	list = (t_data***)ft_memalloc(sizeof(t_data**));
	coor_x = 0;
	while (get_next_line(fd, &line) > 0)
	{	
		coor_z = ft_strsplit(line, ' ');
		j = 0;
		while (coor_z[j])
		{
			
			j++;
		}
		coor_x++;
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (NULL);
	}
	return (list);
}

















/*while (map_char[j])
		{
			w = 0;
			while (w < j)
			{
				list[w] = (t_data**)malloc(sizeof(t_data*));
				w++;
			}
			list[i][j] = (t_data*)malloc(sizeof(t_data));
			list[i][j]->x = i;
			list[i][j]->y = j;
			list[i][j]->z = ft_atoi(map_char[j]);
			j++;
		}
		i++;*/