/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:35:34 by etheodor          #+#    #+#             */
/*   Updated: 2015/01/09 15:02:04 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define DEFAUT_X		1200
# define DEFAUT_Y		800
# define WHITE			0xFFFFFF
# define ORANGE			0xCCC400
# define BLUE			0x32AAFF
# define GREEN			0x107800
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_data
{
	double		x;
	double		y;
	double		z;
	double		s;
}				t_data;

typedef struct	s_pts
{
	int			x;
	int			y;
	int			z;
}				t_pts;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pimg;
	int			bpp;
	int			endian;
	int			size;
	int			size_line;
	int			width;
	double		ecart;
	double		scale;
	t_data		***map;
	double		delta_x;
	double		delta_y;
	double		delta_z;
	t_pts		pts1;
	t_pts		pts2;
	int			a;
	int			b;
	int			*v;
	int			x;
	int			i;
	int			j;
	int			k;
	int			l;
}				t_env;

int				get_next_line(int const fd, char **line);
void			ft_read_data(char *file, t_env *ret);
void			ft_translate(t_env *e, int a, int b);
void			ft_rot_x(t_env *e);
void			ft_print_segment_right(int i, int j, t_env *e);
void			ft_print_segment_down(int i, int j, t_env *e);
void			draw_map(t_env *e);
int				ft_update_img(t_env *ret, void f(t_env *ret));
void			ft_put_pixel_to_image(t_env *ret, int x, int y, int color);
void			ft_close(int fd);
int				ft_open(char *file);
void			ft_map_error(void);
void			ft_error(char *str);
void			ft_mallerr(void);
void			ft_map_error3(t_env *ret, int width);
void			ft_map_error2(char **value);
int				ft_error_arg(int ac);

#endif
