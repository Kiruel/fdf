/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 10:07:07 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/29 10:07:08 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void ft_zoom_more(t_env *e)
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
			e->map[coor_y][coor_x]->y -= 2;
			e->map[coor_y][coor_x]->x -= 2;
			coor_x++;
		}
		coor_y++;
	}
}