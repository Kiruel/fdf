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

void	ft_rot_z(t_env *e)
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
			e->map[coor_y][coor_x]->x = e->map[coor_y][coor_x]->x * cos(0.17453292) + e->map[coor_y][coor_x]->y * -(sin(0.17453292));
			e->map[coor_y][coor_x]->y = e->map[coor_y][coor_x]->x * sin(0.17453292) + e->map[coor_y][coor_x]->y * cos(0.17453292);
			coor_x++;
		}
		coor_y++;
	}
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
			e->map[coor_y][coor_x]->y = e->map[coor_y][coor_x]->y * cos(0.08)
			+ e->map[coor_y][coor_x]->z * -(sin(0.08)); 
			e->map[coor_y][coor_x]->z = e->map[coor_y][coor_x]->y * sin(0.08)
			+ e->map[coor_y][coor_x]->z * cos(0.08);
			coor_x++;
		}
		coor_y++;
	}
}
