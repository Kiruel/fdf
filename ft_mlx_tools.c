#include "includes/fdf.h"

void	ft_put_pixel_to_image(t_env *ret, int x, int y, int color)
{
	int i;

	i = x * 4 + y * ret->size_line;
	ret->pimg[i] = (color & 0xFF);
	ret->pimg[i + 1] = (color & 0xFF00) >> 8;
	ret->pimg[i + 2] = (color & 0xFF0000) >> 16;
}

int		ft_update_img(t_env *ret, void f(t_env *ret))
{
	ret->img = mlx_new_image(ret->mlx, DEFAUT_X, DEFAUT_Y);
	ret->pimg = mlx_get_data_addr(ret->img, &(ret->bpp),
			&(ret->size_line), &(ret->endian));
	f(ret);
	mlx_put_image_to_window(ret->mlx, ret->win, ret->img, 0, 0);
	mlx_destroy_image(ret->mlx, ret->img);
	return (0);
}
