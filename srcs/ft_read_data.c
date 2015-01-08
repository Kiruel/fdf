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
	int			i;
	int			x;
	int			width;
	char		**value;

	value = ft_strsplit(buf, ' ');
	i = ft_map_width(value);
	x = -1;
	width = 0;
	if ((line = (t_data**)ft_memalloc(sizeof(t_data*) * i + 1)) == NULL)
		ft_mallerr();
	while (++x < i)
	{
		if ((line[x] = (t_data*)ft_memalloc(sizeof(t_data))) == NULL)
			ft_mallerr();
		line[x]->z = ft_atoi(value[x]);
		line[x]->x = width;
		line[x]->y = y;
		line[x]->s = 1;
		width++;
	}
	ret->size_line = width;
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
		ret->map[ret->size] = ft_add_entry(buf, height, ret);
		free(buf);
		ret->size++;
		height++;
	}
	if (rt == -1)
		ft_error("gnl");
}
