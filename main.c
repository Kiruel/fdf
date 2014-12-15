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

t_data *add_link_first(t_data *list, int i, char *map_char)
{
	t_data *tmp;
	tmp = malloc(sizeof(t_data));
	if (tmp)
	{
		tmp->x = 0;
		tmp->y = i;
		tmp->z = ft_atoi(map_char);
		tmp->next = list;
	}
	return (tmp);
}

int main(int ac, char **av)
{
	t_data 	*list;
	char 	*line;
	char 	**map_char;
	int 	fd;
	int 	i;
	// int     j;

	if (ac < 2)
		return (0);
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("opent() failed\n");
		return (0);
	}
	if (get_next_line(fd, &line) == -1)
		return (0);
	map_char = ft_strsplit(line, ' ');
	list = NULL;
	i = 0;
	while (map_char[i])
	{
		list = add_link_first(list, i, map_char[i]);
		i++;
	}
	i = 1;
	/*while (get_next_line(fd, &line))
	{	
		map_char = ft_strsplit(line, ' ');
		j = 0;
		while (map_char[j])
		{
			tmp->x = i;
			tmp->y = j;
			tmp->z = ft_atoi(map_char[j]);
			list = tmp;
			tmp = tmp->next;
			j++;
		}
		i++;
	}*/
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}

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