/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 14:36:37 by etheodor          #+#    #+#             */
/*   Updated: 2015/01/02 14:36:38 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_pixel(t_env *e, int x, int y, int color)
{
	if ((x < DEFAUT_X && x > 0) && (y < DEFAUT_Y && y > 0))
		ft_put_pixel_to_image(e, x, y, color);
}

void	ft_print_color(t_env *e, int x, int y)
{
	if (e->map[e->i + e->a][e->j + e->b])
	{
		if (e->map[e->i + e->a][e->j + e->b]->z <= 0 ||
			e->map[e->i][e->j]->z <= 0)
			ft_print_pixel(e, x, y, BLUE);
		else if ((e->map[e->i + e->a][e->j + e->b]->z >= 1 ||
			e->map[e->i][e->j]->z >= 1) &&
			(e->map[e->i + e->a][e->j + e->b]->z <= 3 ||
				e->map[e->i][e->j]->z <= 3))
			ft_print_pixel(e, x, y, ORANGE);
		else if (e->map[e->i + e->a][e->j + e->b]->z >= 4 ||
			e->map[e->i][e->j]->z >= 4)
			ft_print_pixel(e, x, y, GREEN);
		else
			ft_print_pixel(e, x, y, WHITE);
	}
}

void	ft_print_segment(t_env *e)
{
	e->v[0] = abs(e->v[7] - e->v[6]);
	e->v[2] = e->v[6] < e->v[7] ? 1 : -1;
	e->v[1] = abs(e->v[9] - e->v[8]);
	e->v[3] = e->v[8] < e->v[9] ? 1 : -1;
	e->v[4] = (e->v[0] > e->v[1] ? e->v[0] : -(e->v[1])) / 2;
	while (1)
	{
		ft_print_color(e, e->v[6], e->v[8]);
		if ((e->v[6] == e->v[7]) && (e->v[8] == e->v[9]))
			break ;
		e->v[5] = e->v[4];
		if (e->v[5] > -(e->v[0]))
			e->v[4] -= e->v[1];
		if (e->v[5] > -(e->v[0]))
			e->v[6] += e->v[2];
		if (e->v[5] < e->v[1])
			e->v[4] += e->v[0];
		if (e->v[5] < e->v[1])
			e->v[8] += e->v[3];
	}
}

void	ft_print_segment_all(t_env *e, int a, int b)
{
	e->a = a;
	e->b = b;
	e->pts1.x = (e->map[e->i][e->j]->x - e->map[e->i][e->j]->y) *
	e->ecart + 500;
	e->pts1.y = (e->map[e->i][e->j]->x + e->map[e->i][e->j]->y) *
	(e->ecart) / 2 + 250;
	e->pts1.z = e->map[e->i][e->j]->z * e->ecart * e->scale;
	e->pts2.x = (e->map[e->i + a][e->j + b]->x -
		e->map[e->i + a][e->j + b]->y) * e->ecart + 500;
	e->pts2.y = (e->map[e->i + a][e->j + b]->x +
		e->map[e->i + a][e->j + b]->y) * (e->ecart) / 2 + 250;
	e->pts2.z = e->map[e->i + a][e->j + b]->z * e->ecart * e->scale;
	e->v[6] = e->pts1.x;
	e->v[8] = e->pts1.y - e->pts1.z;
	e->v[7] = e->pts2.x;
	e->v[9] = e->pts2.y - e->pts2.z;
	if (((e->v[6] <= DEFAUT_X && e->v[6] >= 0) && (e->v[8] <= DEFAUT_Y &&
		e->v[8] >= 0)) || ((e->v[7] <= DEFAUT_X && e->v[7] >= 0) &&
		(e->v[9] <= DEFAUT_Y && e->v[9] >= 0)))
		ft_print_segment(e);
}

void	draw_map(t_env *e)
{
	e->i = 0;
	e->j = 0;
	while (e->i < e->size + 1)
	{
		if (e->map[e->i])
		{
			e->j = 0;
			while (e->map[e->i][e->j])
			{
				if (e->map[e->i][e->j + 1] && e->map[e->i][e->j])
					ft_print_segment_all(e, 0, 1);
				if (e->map[e->i + 1])
					if (e->map[e->i + 1][e->j])
						ft_print_segment_all(e, 1, 0);
				e->j++;
			}
		}
		e->i++;
	}
}
