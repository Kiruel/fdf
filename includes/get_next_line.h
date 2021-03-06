/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:02:10 by etheodor          #+#    #+#             */
/*   Updated: 2015/01/09 15:08:31 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF 100
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct		s_lst
{
	char			*buf;
	int				fd;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(int const fd, char **line);
#endif
