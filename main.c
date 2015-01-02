/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:40:39 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/28 17:41:38 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*int		mouse_hook(int buttons, int x, int y, t_env *e)
{
	e++;
	write(1, "key: ", 5);
	ft_putnbr(buttons);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putchar(':');
	ft_putnbr(y);
	ft_putchar(')');
	ft_putchar('\n');
	return (0);
}*/

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	draw_map(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
	{
		free(e);
		while (42)
			;
		exit(0);
	}
	// write(1, "key: ", 5);
	// ft_putnbr(keycode);
	// ft_putchar('\n');
	if (keycode == 65363)
		ft_translate_more(e);
	if (keycode == 65361)
		ft_translate_less(e);
	if (keycode == 65362)
		ft_translate_up(e);
	if (keycode == 65364)
		ft_translate_down(e);
	if (keycode == 65457)
		ft_rot_x(e);
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
	ft_read_data(av[1], e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, size[0], size[1], "fdf");
	e->ecart = 20;
	e->scale = 0.1;
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	free(size);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e->mlx);
	return (0);
}
