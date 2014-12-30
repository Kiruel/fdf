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
#define DEFAUT_X		1200
#define DEFAUT_Y		800
#define COLOR_PIXEL		0xFCFFFE

/*static void		ft_draw_line(t_env e, int i, int j, int v[10])
{
	v[6] = e->map[i][j]->x * e.space_x;
	v[8] = e->map[i][j]->y * e.space_y;
	v[7] = e->map[i][j + 1]->x * e.space_x;
	v[9] = e->map[i][j + 1]->y * e.space_y;
	v[0] = abs(v[7] - v[6]);
	v[2] = v[6] < v[7] ? 1 : -1;
	v[1] = abs(v[9] - v[8]);
	v[3] = v[8] < v[9] ? 1 : -1;
	v[4] = (v[0] > v[1] ? v[0] : -v[1]) / 2;
	while (1)
	{
		mlx_pixel_put(e.mlx, e.win, v[6] + e.o_x, v[8] + e.o_y, e.color);
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
}*/

void	ft_print_map(int i, int j, t_env *e)
{
	int x;
	int y;
	int z;

	x = (e->map[i][j]->x - e->map[i][j]->y) * e->ecart + 500;
	y = (e->map[i][j]->x + e->map[i][j]->y) * (e->ecart)/2 + 250;
	z = e->map[i][j]->z * e->ecart * e->scale;
	if (e->map[i][j]->z < 0 && e->map[i][j]->z > -80)
		mlx_pixel_put(e->mlx, e->win, x, y - z, 0x00B5FF);
	else if (e->map[i][j]->z < -81 && e->map[i][j]->z > -160)
		mlx_pixel_put(e->mlx, e->win, x, y - z, 0x0061DB);
	else if (e->map[i][j]->z < -160)
		mlx_pixel_put(e->mlx, e->win, x, y - z, 0x0048A3);
	else if (e->map[i][j]->z > 0 && e->map[i][j]->z < 40)
		mlx_pixel_put(e->mlx, e->win, x, y - z, 0xF5D37D);
	else if (e->map[i][j]->z > 41 && e->map[i][j]->z < 80)
		mlx_pixel_put(e->mlx, e->win, x, y - z, 0x157A0A);
	else if (e->map[i][j]->z > 81 && e->map[i][j]->z < 400)
		mlx_pixel_put(e->mlx, e->win, x, y - z, 0x523C0B);
	else
		mlx_pixel_put(e->mlx, e->win, x, y - z, COLOR_PIXEL);
}

void	draw_map(t_env *e)
{
	int i;
	int j;
	// int *v;

	i = 0;
	j = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			ft_print_map(i, j, e);
			// ft_draw_line(e, i, j, v);
			j++;
		}
		i++;
	}
}

void	draw_square(void *mlx, void *win)
{
	int x;
	int y;

	y = 0;
	while (y < DEFAUT_Y)
	{
		x = 0;
		while (x < DEFAUT_X)
		{
			mlx_pixel_put(mlx, win, x, y, 0x000000);
			x++;
		}
		y++;
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

int		expose_hook(t_env *e)
{
	draw_square(e->mlx, e->win);
	draw_map(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	write(1, "key: ", 5);
	ft_putnbr(keycode);
	ft_putchar('\n');
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
        	e->ecart--;
    if (keycode == 61 || keycode == 65451)
    	if (e->ecart >= 0)
        	e->ecart++;
    if (keycode == 65365 || keycode == 108)
        e->scale += 0.1;
    if (keycode == 65366 || keycode == 59)
        e->scale -= 0.1;
	expose_hook(e);
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
		size[0] = DEFAUT_X;
		size[1] = DEFAUT_Y;
	}
	else
	{
		size[0] = ft_atoi(av[2]);
		size[1] = ft_atoi(av[3]);
	}
	if (ac > 4)
		return (0);
	if (ac < 2)
	{
		ft_putstr_fd("Missing args after binary.", 2);
		ft_putchar('\n');
		return (0);
	}
	list = NULL;
	list = ft_read_data(av);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, size[0], size[1], "fdf");
	e.map = list;
	e.ecart = 20;
	e.scale = 0.1;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	free(list);
	return (0);
}
