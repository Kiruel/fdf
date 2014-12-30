/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 09:09:16 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/29 09:09:17 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#define VALEUR_T	3

void	ft_translate_down(t_env *e)
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
			e->map[coor_y][coor_x]->y += VALEUR_T;
			coor_x++;
		}
		coor_y++;
	}
}

void	ft_translate_up(t_env *e)
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
			e->map[coor_y][coor_x]->y -= VALEUR_T;
			coor_x++;
		}
		coor_y++;
	}
}

void	ft_translate_less(t_env *e)
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
			e->map[coor_y][coor_x]->x -= VALEUR_T;
			coor_x++;
		}
		coor_y++;
	}
}

void	ft_translate_more(t_env *e)
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
			e->map[coor_y][coor_x]->x += VALEUR_T;
			coor_x++;	
		}
		coor_y++;
	}
}
