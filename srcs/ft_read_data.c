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

#include "fdf.h"

static int		ft_map_width(char **value)
{
	int		i;

	i = 0;
	while (value[i])
		i++;
	return (i);
}

static t_data	**ft_add_entry(char *buf, int y, t_env *ret)
{
	t_data		**line;
	int			width;
	char		**value;

	value = ft_strsplit(buf, ' ');
	ft_map_error2(value);
	ret->x = -1;
	width = 0;
	if ((line = (t_data**)ft_memalloc(sizeof(t_data*) *
		ft_map_width(value) + 1)) == NULL)
		ft_mallerr();
	while (++ret->x < ft_map_width(value))
	{
		if ((line[ret->x] = (t_data*)ft_memalloc(sizeof(t_data))) == NULL)
			ft_mallerr();
		line[ret->x]->z = ft_atoi(value[ret->x]);
		line[ret->x]->x = width;
		line[ret->x]->y = y;
		line[ret->x]->s = 1;
		free(value[ret->x]);
		width++;
	}
	ft_map_error3(ret, width);
	free(value);
	return (ft_map_width(value) ? line : NULL);
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
		ret->map[ret->size] = ft_add_entry(buf, height, ret);
		free(buf);
		ret->size++;
		height++;
	}
	if (rt == -1)
		ft_error("gnl");
}
