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

void 	ft_print_color(t_env *e, int x, int y, int i, int j)
{
	(void)i;
	(void)j;
	if (e->map[i + e->a][j + e->b])
	{
		if (e->map[i + e->a][j + e->b]->z >= 10 || e->map[i][j]->z >= 10)
			ft_print_pixel(e, x, y, 0xFF0000);
		else
			ft_print_pixel(e, x, y, 0xFFFFFF);
	}
}

void 	ft_print_segment(t_env *e, int i, int j)
{
	e->v[0] = abs(e->v[7] - e->v[6]);
	e->v[2] = e->v[6] < e->v[7] ? 1 : -1;
	e->v[1] = abs(e->v[9] - e->v[8]);
	e->v[3] = e->v[8] < e->v[9] ? 1 : -1;
	e->v[4] = (e->v[0] > e->v[1] ? e->v[0] : -(e->v[1])) / 2;
	while (1)
	{
		ft_print_color(e, e->v[6], e->v[8], i, j);
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

void	ft_print_segment_all(int i, int j, t_env *e, int a, int b)
{
	e->a = a;
	e->b = b;
	e->pts1[0] = (e->map[i][j]->x - e->map[i][j]->y) * e->ecart + 500;
	e->pts1[1] = (e->map[i][j]->x + e->map[i][j]->y) * (e->ecart)/2 + 250;
	e->pts1[2] = e->map[i][j]->z * e->ecart * e->scale;
	e->pts2[0] = (e->map[i + a][j + b]->x - e->map[i + a][j + b]->y) * e->ecart + 500;
	e->pts2[1] = (e->map[i + a][j + b]->x + e->map[i + a][j + b]->y) * (e->ecart)/2 + 250;
	e->pts2[2] = e->map[i + a][j + b]->z * e->ecart * e->scale;
	e->v[6] = e->pts1[0];
	e->v[8] = e->pts1[1] - e->pts1[2];
	e->v[7] = e->pts2[0];
	e->v[9] = e->pts2[1] - e->pts2[2];
	if (((e->v[6] <= DEFAUT_X && e->v[6] >= 0) && (e->v[8] <= DEFAUT_Y &&
		e->v[8] >= 0)) || ((e->v[7] <= DEFAUT_X && e->v[7] >= 0) &&
		(e->v[9] <= DEFAUT_Y && e->v[9] >= 0)))
			ft_print_segment(e, i, j);
}

void	draw_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->size + 1)
	{
		if (e->map[i])
		{
			j = 0;
			while (e->map[i][j])
			{
				if (e->map[i][j + 1] && e->map[i][j])
					ft_print_segment_all(i, j, e, 0, 1);
				if (e->map[i + 1])
					if (e->map[i + 1][j])
						ft_print_segment_all(i, j, e, 1, 0);
				j++;
			}
		}
		i++;
	}
}
