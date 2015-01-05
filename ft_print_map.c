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

#include "includes/fdf.h"

void	ft_print_pixel(t_env *e, int x, int y, int color)
{
	if ((x <= DEFAUT_X && x >= 0) && (y <= DEFAUT_Y && y >= 0))
		mlx_pixel_put(e->mlx, e->win, x, y, color);
}

void 	ft_print_color(t_env *e, int x, int y, int i, int j)
{
	(void)i;
	(void)j;
	if (e->map[i][j]->z == 10)
		ft_print_pixel(e, x, y, 0xFFFFFF);
	else
		ft_print_pixel(e, x, y, 0xFFFFFF);
}

void 	ft_print_segment(t_env *e, int *pts1, int *pts2, int i, int j)
{
	int *v;

	v = (int*)ft_memalloc(sizeof(int) * 10);
	v[6] = pts1[0];
	v[8] = pts1[1] - pts1[2];
	v[7] = pts2[0];
	v[9] = pts2[1] - pts2[2];
	v[0] = abs(v[7] - v[6]);
	v[2] = v[6] < v[7] ? 1 : -1;
	v[1] = abs(v[9] - v[8]);
	v[3] = v[8] < v[9] ? 1 : -1;
	v[4] = (v[0] > v[1] ? v[0] : -v[1]) / 2;
	while (1)
	{
		ft_print_color(e, v[6], v[8], i, j);
		if ((v[6] == v[7]) && (v[8] == v[9]))
			break ;
		v[5] = v[4];
		if (v[5] > -v[0])
			v[4] -= v[1];
		if (v[5] > -v[0])
			v[6] += v[2];
		if (v[5] < v[1])
			v[4] += v[0];
		if (v[5] < v[1])
			v[8] += v[3];
	}
	free(pts1);
	free(pts2);
}

void	ft_print_segment_right(int i, int j, t_env *e)
{
	int *pts1;
	int *pts2;

	pts1 = (int*)ft_memalloc(sizeof(int) * 3);
	pts2 = (int*)ft_memalloc(sizeof(int) * 3);
	pts1[0] = (e->map[i][j]->x - e->map[i][j]->y) * e->ecart + 500;
	pts1[1] = (e->map[i][j]->x + e->map[i][j]->y) * (e->ecart)/2 + 250;
	pts1[2] = e->map[i][j]->z * e->ecart * e->scale;
	pts2[0] = (e->map[i][j + 1]->x - e->map[i][j + 1]->y) * e->ecart + 500;
	pts2[1] = (e->map[i][j + 1]->x + e->map[i][j + 1]->y) * (e->ecart)/2 + 250;
	pts2[2] = e->map[i][j + 1]->z * e->ecart * e->scale;
	ft_print_segment(e, pts1, pts2, i, j);
}

void	ft_print_segment_down(int i, int j, t_env *e)
{
	int *pts1;
	int *pts2;

	pts1 = (int*)ft_memalloc(sizeof(int) * 3);
	pts2 = (int*)ft_memalloc(sizeof(int) * 3);
	pts1[0] = (e->map[i][j]->x - e->map[i][j]->y) * e->ecart + 500;
	pts1[1] = (e->map[i][j]->x + e->map[i][j]->y) * (e->ecart)/2 + 250;
	pts1[2] = e->map[i][j]->z * e->ecart * e->scale;
	pts2[0] = (e->map[i + 1][j]->x - e->map[i + 1][j]->y) * e->ecart + 500;
	pts2[1] = (e->map[i + 1][j]->x + e->map[i + 1][j]->y) * (e->ecart)/2 + 250;
	pts2[2] = e->map[i + 1][j]->z * e->ecart * e->scale;
	ft_print_segment(e, pts1, pts2, i, j);
}

void	draw_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->size)
	{
		if (e->map[i])
		{
			j = 0;
			while (e->map[i][j])
			{
				if (e->map[i][j + 1] && e->map[i][j])
					ft_print_segment_right(i, j, e);
				if (e->map[i + 1])
					if (e->map[i + 1][j])
						ft_print_segment_down(i, j, e);
				j++;
			}			
		}
		i++;
	}
}
