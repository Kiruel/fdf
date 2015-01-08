/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 09:09:16 by etheodor          #+#    #+#             */
/*   Updated: 2014/12/29 09:09:17 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define VALEUR_T	3

void	ft_translate2(t_env *e, int i, int j, int a, int b)
{
	if (a == 0 && b == 0)
		e->map[i][j]->x += VALEUR_T;
	if (a == 0 && b == 1)
		e->map[i][j]->x -= VALEUR_T;
	if (a == 1 && b == 0)
		e->map[i][j]->y -= VALEUR_T;
	if (a == 1 && b == 1)
		e->map[i][j]->y += VALEUR_T;
}

void	ft_translate(t_env *e, int a, int b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->size)
	{
		if (e->map[i])
		{
			j = 0;
			while (e->map[i][j])
			{
				ft_translate2(e, i, j, a, b);
				j++;
			}			
		}
		i++;
	}
}
