/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:40:39 by etheodor          #+#    #+#             */
/*   Updated: 2015/01/08 15:19:37 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate_map(int keycode, t_env *e)
{
	if (keycode == 65363)
		ft_translate(e, 0, 0);
	if (keycode == 65361)
		ft_translate(e, 0, 1);
	if (keycode == 65362)
		ft_translate(e, 1, 0);
	if (keycode == 65364)
		ft_translate(e, 1, 1);
}

int		expose_hook(t_env *e)
{
	e->pts1 = (int*)ft_memalloc(sizeof(int) * 3);
	e->pts2 = (int*)ft_memalloc(sizeof(int) * 3);
	ft_update_img(e, draw_map);
	free(e->pts1);
	free(e->pts2);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	ft_translate_map(keycode, e);
	if (keycode == 45 || keycode == 65453)
		if (e->ecart > 0)
			e->ecart -= 1;
	if (keycode == 61 || keycode == 65451)
		if (e->ecart >= 0)
			e->ecart += 1;
	if (keycode == 65365 || keycode == 108)
		e->scale += 0.1;
	if (keycode == 65366 || keycode == 59)
		e->scale -= 0.1;
	expose_hook(e);
	return (0);
}

int 	main(int ac, char **av)
{
	t_env	*e;
	int 	*size;

	size = (int*)ft_memalloc(sizeof(int) * 2);
	size[0] = DEFAUT_X;
	size[1] = DEFAUT_Y;
	if (ac > 2)
		return (0);
	if (ac < 2)
	{
		ft_putstr_fd("Missing args after binary.", 2);
		ft_putchar('\n');
		return (0);
	}
	if ((e = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
		ft_mallerr();
	e->v = (int*)ft_memalloc(sizeof(int) * 10);
	ft_read_data(av[1], e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, size[0], size[1], "fdf");
	free(size);
	e->ecart = 20;
	e->scale = 0.1;
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
