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

void	ft_translate2(t_env *e, int a, int b)
{
	if (a == 0 && b == 0)
		e->map[e->k][e->l]->x += VALEUR_T;
	if (a == 0 && b == 1)
		e->map[e->k][e->l]->x -= VALEUR_T;
	if (a == 1 && b == 0)
		e->map[e->k][e->l]->y -= VALEUR_T;
	if (a == 1 && b == 1)
		e->map[e->k][e->l]->y += VALEUR_T;
}

void	ft_translate(t_env *e, int a, int b)
{
	e->k = 0;
	e->l = 0;
	while (e->k < e->size)
	{
		if (e->map[e->k])
		{
			e->l = 0;
			while (e->map[e->k][e->l])
			{
				ft_translate2(e, a, b);
				e->l++;
			}
		}
		e->k++;
	}
}
