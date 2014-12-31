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
# include <math.h>

typedef struct 	s_data
{
	double		x;
	double 		y;
	double 		z;
	double		s;
}				t_data;

typedef struct	s_env
{
	void 		*mlx;
	void 		*win;
	int			size;
	double 		ecart;
	double		scale;
	t_data		***map;
}				t_env;

int			get_next_line(int const fd, char **line);
void		ft_read_data(char *file, t_env *ret);
void		ft_translate_down(t_env *e);
void		ft_translate_up(t_env *e);
void		ft_translate_more(t_env *e);
void		ft_translate_less(t_env *e);
void		ft_rot_x(t_env *e);
void		draw_point_white(t_env *e, int i, int j);
void		draw_point(t_env *e, int i, int j);
char		**ft_strsplit_fdf(char const *s);

//error
void		ft_close(int fd);
int			ft_open(char *file);
void		ft_map_error(void);
void		ft_error(char *str);
void		ft_mallerr(void);

#endif
