/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 10:47:20 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/31 10:47:21 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mallerr(void)
{
	ft_putendl_fd("malloc error", 2);
	exit(2);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Somethings went wrong with:", 2);
	ft_putendl_fd(str, 2);
	exit(2);
}

void	ft_map_error(void)
{
	ft_putendl_fd("map error", 2);
	exit (2);
}

int		ft_open(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("open");
	return (fd);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		ft_error("close");
}
