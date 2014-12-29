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

static float ft_rad(float x)
{
	const float Pi = 3.141592654f;

	return (x * Pi / 180);
}

/*void	ft_rot_z(t_env *e)
{
	int 	coor_x;
	int 	coor_y;
	int		x;
	int 	y;

	x = 0;
	y = 0;
	coor_x = 0;
	coor_y = 0;
	while (e->map[coor_y])
	{
		coor_x = 0;
		while (e->map[coor_y][coor_x])
		{
			x = (e->map[coor_y][coor_x]->x - e->map[coor_y][coor_x]->y) * 20;
			y = (e->map[coor_y][coor_x]->x + e->map[coor_y][coor_x]->y) * 10;
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFFFFFF);
			coor_x++;
		}
		coor_y++;
	}
}*/

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
			e->map[coor_y][coor_x]->y = e->map[coor_y][coor_x]->y * cos(ft_rad(5)) - e->map[coor_y][coor_x]->z * sin(ft_rad(5)); 
			e->map[coor_y][coor_x]->z = e->map[coor_y][coor_x]->y * sin(ft_rad(5)) + e->map[coor_y][coor_x]->z * cos(ft_rad(5));
			coor_x++;
		}
		coor_y++;
	}
}
