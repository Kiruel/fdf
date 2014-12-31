/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 09:11:50 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/29 09:11:50 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#define COLOR_PIXEL_Z	0xD77B28

void	draw_point(t_env *e, int i, int j)
{
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y - 1 + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 1 + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x - 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y - 2 + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 2 + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x - 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y - 1 + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y - 1 + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x - 2 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 2 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x - 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 1 + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 2 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 1 + (e->ecart * (i + 1))), COLOR_PIXEL);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x  + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 2 + (e->ecart * (i + 1))), COLOR_PIXEL);

}

void	draw_point_white(t_env *e, int i, int j)
{
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y - 1 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 1 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x - 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y - 2 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 2 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x - 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y - 1 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y - 1 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x - 2 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 2 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x - 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 1 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 2 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x + 1 + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 1 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
	mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->x  + (e->ecart * (j + 1))),
		(e->map[i][j]->y + 2 + (e->ecart * (i + 1))), COLOR_PIXEL_Z);
}
