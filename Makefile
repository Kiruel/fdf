#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 15:13:13 by etheodor          #+#    #+#              #
#    Updated: 2014/11/24 16:30:50 by etheodor         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CFLAG = -Wall -Werror -Wextra 

SOURCE = main.c

POINTO = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc -c $(SOURCE) -L libft/ -lft -L/usr/x11/lib -lmlx -lXext -lX11
	@gcc -o $(NAME) $(POINTO) -L libft/ -lft -I includes/ -L/usr/x11/lib -lmlx -lXext -lX11
	@make clean

test:
	@gcc -c $(SOURCE) -L libft/ -lft
	@gcc -o $(NAME) $(POINTO) -L libft/ -lft -I includes/ -L/usr/x11/lib -lmlx -lXext -lX11
	@make clean

clean:
	@rm -rf $(POINTO)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
