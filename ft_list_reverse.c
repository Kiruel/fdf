/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 09:13:36 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/27 09:37:21 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_list_reverse(t_data **begin_list)
{
	t_data *prev;
	t_data *cur;
	t_data *ret;

	prev = NULL;
	ret = NULL;
	cur = *begin_list;
	while (cur)
	{
		prev = cur;
		cur = prev->next;
		prev->next = ret;
		ret = prev;
	}
	*begin_list = ret;
}
