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
#define ECART	5

void	draw_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (e->map[i][j]->z >= 10)
			{
			mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->y + (ECART * (j + 1))),
				(e->map[i][j]->x + (ECART * (i + 1))), 0xFFFFFF);				
			}
			else
			{
			mlx_pixel_put(e->mlx, e->win, (e->map[i][j]->y + (ECART * (j + 1))),
				(e->map[i][j]->x + (ECART * (i + 1))), 0xFF0000);				
			}
			j++;
		}
		i++;
	}
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
	int 	*size;

	size = (int*)ft_memalloc(sizeof(int) * 2);

	if (ac < 4)
	{
		size[0] = 1200;
		size[1] = 1000;
	}
	else
	{
		size[0] = ft_atoi(av[2]);
		size[1] = ft_atoi(av[3]);
	}
	if (ac > 4)
		return (0);
	list = NULL;
	list = ft_read_data(av);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, size[0], size[1], "fdf");
	e.map = list; 
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	free(list);
	return (0);
}
