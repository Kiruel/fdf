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

MINILIBX = -L/usr/x11/lib -lmlx -lXext -lX11

LIBFT = ./libft/includes

SOURCE = main.c \
	get_next_line.c \
	ft_read_data.c \
	ft_translate.c \
	ft_draw_point.c \
	ft_rot.c

POINTO = $(SOURCE:.c=.o)

all: $(NAME)
	@echo "all: OK"

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc -c $(CFLAG) $(SOURCE) -I $(LIBFT)
	@gcc $(CFLAG) -o $(NAME) $(POINTO) ./libft/libft.a -L/usr/x11/lib -lmlx -lXext -lX11
	@make clean

test:
	@gcc -c $(CFLAG) $(SOURCE)
	@gcc $(CFLAG) -o $(NAME) $(POINTO) ./libft/libft.a -L/usr/x11/lib -lmlx -lXext -lX11
	@make clean
	@echo "test: OK"

clean:
	@rm -rf $(POINTO)

fclean: clean
	@rm -rf $(NAME)
	@echo "fclean: OK"

re: fclean all

.PHONY: re fclean clean all $(NAME) test