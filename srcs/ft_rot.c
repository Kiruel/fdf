/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 12:06:25 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/29 12:06:25 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/fdf.h"

static double ft_rad(double x)
{
	const double Pi = 3.141592653589;

	return (x * Pi / 180);
}

void	ft_rot_x(t_env *e)
{
	int coor_x;
	int coor_y;

	coor_x = 0;
	coor_y = 0;
	while (e->map[coor_y])
	{
		coor_x = 0;
		while (e->map[coor_y][coor_x])
		{
			e->map[coor_y][coor_x]->y = e->map[coor_y][coor_x]->y * cos(ft_rad(10)) - e->map[coor_y][coor_x]->z * sin(ft_rad(10)); 
			e->map[coor_y][coor_x]->z = e->map[coor_y][coor_x]->y * sin(ft_rad(10)) + e->map[coor_y][coor_x]->z * cos(ft_rad(10));
			coor_x++;
		}
		coor_y++;
	}
}
