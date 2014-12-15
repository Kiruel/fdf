/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:01:10 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/19 15:18:04 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"


static int	ft_to_fill(char **line, char **ptr)
{
	int		i;
	char	*old;

	i = 0;
	while ((*ptr)[i] != '\n' && (*ptr)[i] != '\0')
		i++;
	old = (char*)ft_memalloc(sizeof(char) * i + 1);
	i = 0;
	while ((*ptr)[i] != '\n' && (*ptr)[i] != '\0')
	{
		old[i] = (*ptr)[i];
		i++;
	}
	old[i] = '\0';
	if (*line)
		*line = ft_strjoin(*line, old);
	else
		*line = *ptr;
	if ((*ptr)[i] == '\n')
	{
		*ptr = &(*ptr)[i + 1];
		return (1);
	}
	return (0);
}

static int	ft_read(char **str, int fd)
{
	int		i;
	char	*buff;

	buff = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	i = read(fd, buff, BUFF_SIZE);
	if (i == -1)
		return (-1);
	*str = buff;
	return (i);
}

int			get_next_line(int const fd, char **line)
{
	static char *str;
	int			i;

	*line = 0;
	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (str != 0)
	{
		if (ft_to_fill(line, &str) == 1)
			return (1);
	}
	i = 1;
	while (i)
	{
		i = ft_read(&str, fd);
		if (i == -1)
			return (-1);
		if (ft_to_fill(line, &str) == 1)
			return (1);
	}
	return (i);
}
