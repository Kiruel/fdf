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

void	ft_translate_down(t_env *e)
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
				e->map[i][j]->y += VALEUR_T;
				j++;
			}			
		}
		i++;
	}
}

void	ft_translate_up(t_env *e)
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
				e->map[i][j]->y -= VALEUR_T;
				j++;
			}			
		}
		i++;
	}
}

void	ft_translate_less(t_env *e)
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
				e->map[i][j]->x -= VALEUR_T;
				j++;
			}			
		}
		i++;
	}
}

void	ft_translate_more(t_env *e)
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
				e->map[i][j]->x += VALEUR_T;
				j++;
			}			
		}
		i++;
	}
}
