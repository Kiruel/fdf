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

int 	main(int ac, char **av)
{
	t_data ***list;

	list = NULL;
	if (ac == 2)
	{
		list = ft_read_data(av);
		ft_putnbr(list[2][11]->z);
		ft_putchar('\n');		
	}
	list++;
	return (0);
}

/*void	draw_square(void *mlx, void *win)
{
	int x;
	int y;

	y = 100;
	while (y < 300)
	{
		x = 100;
		while (x < 300)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

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

int		mouse_hook(int buttons, int x, int y, t_env *e)
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
}

int		expose_hook(t_env *e)
{
	draw_square(e->mlx, e->win);
	return (0);
}
int main()
{
	// t_env 	e;

	// e.mlx = mlx_init();
	// e.win = mlx_new_window(e.mlx, 600, 600, "fdf");
}
*/