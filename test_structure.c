#include <stdlib.h>

typedef struct 	s_data
{
	int	x;
	int y;
	int z;
}	t_data;


void main()
{
	int i;
	int j;
	int k;
	t_data ***list;

	i = 0;
	list = NULL;
	list = (t_data***)malloc(sizeof(t_data**));
	while (i < 10)
	{
		k = 0;
		while (k < 10)
		{
			list[i] = (t_data**)malloc(sizeof(t_data*));
			k++;
		}
		list[i][j] = (t_data*)malloc(sizeof(t_data));
		list[i][j]->x = 10;
		i++;
	}
	list[0][0]->x = 10;
	ft_putnbr(list[0][0]->x);
}