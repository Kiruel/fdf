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

void	draw_map(t_env *e)
{
	ft_putnbr(e->poil);
	ft_putchar('\n');
	mlx_pixel_put(e->mlx, e->win, 100, 100, 0xFF0000);
}

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

int		key_hook(int keycode, t_env *e)
{
	e++;
	if (keycode == 65307)
		exit(0);
	write(1, "key: ", 5);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		expose_hook(t_env *e)
{
	draw_map(e);
	return (0);
}

int 	main(int ac, char **av)
{
	t_data 	***list;
	t_env	e;

	if (ac < 4)
	{
		ft_putstr_fd("Error: Miss x and y window on argument 2-3\n", 2);
		return (0);
	}
	if (ac > 4)
		return (0);
	list = NULL;
	if (ac == 2)
	{
		list = ft_read_data(av);
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, ft_atoi(av[2]), ft_atoi(av[3]), "fdf");
	e.poil = 23;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	free(list);
	return (0);
}
