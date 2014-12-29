/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:35:34 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/28 17:35:35 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>

typedef struct 	s_data
{
	int			x;
	int 		y;
	int 		z;
}				t_data;

typedef struct	s_env
{
	void 		*mlx;
	void 		*win;
	int			poil;
	t_data		***map;
}				t_env;

int			get_next_line(int const fd, char **line);
t_data		***ft_read_data(char **av);
void		ft_translate_down(t_env *e);
void		ft_translate_up(t_env *e);
void		ft_translate_more(t_env *e);
void		ft_translate_less(t_env *e);
void		draw_point_white(t_env *e, int i, int j);
void		draw_point(t_env *e, int i, int j);

#endif
