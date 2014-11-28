/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 13:52:34 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/28 13:52:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_complete(char ***tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			tab[0][j][k] = s[i];
			k++;
			i++;
		}
		tab[0][j][k] = '\0';
		i++;
		j++;
	}
}

void	ft_malloc_tab(char ***tab, char const *s, char c)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			size++;
			i++;
		}
		tab[0][j] = (char*)malloc(sizeof(char) * size + 1);
		j++;
		i++;
	}
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		match;
	char	**tab;

	i = 0;
	match = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		match++;
		while (s[i] != c)
			i++;
		i++;
	}
	tab = (char**)malloc(sizeof(char*) * match + 1);
	ft_malloc_tab(&tab, s, c);
	ft_complete(&tab, s, c);
	return (tab);
}
