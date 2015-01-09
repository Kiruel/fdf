#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 15:13:13 by etheodor          #+#    #+#              #
#    Updated: 2015/01/05 09:44:47 by etheodor         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CFLAG = -Wall -Werror -Wextra -I ./includes

MINILIBX = -L/usr/x11/lib -lmlx -lXext -lX11

LIBFT = ./libft/includes

SOURCE = ./srcs/main.c \
	./srcs/get_next_line.c \
	./srcs/ft_read_data.c \
	./srcs/ft_translate.c \
	./srcs/ft_error.c \
	./srcs/ft_print_map.c \
	./srcs/ft_mlx_tools.c \
	./srcs/ft_error2.c

POINTO = main.o \
	get_next_line.o \
	ft_read_data.o \
	ft_translate.o \
	ft_error.o \
	ft_print_map.o \
	ft_mlx_tools.o \
	ft_error2.o

all: $(NAME)
	@echo "all: OK"

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc -c -g $(CFLAG) $(SOURCE) -I $(LIBFT)
	@gcc $(CFLAG) -o $(NAME) $(POINTO) ./libft/libft.a -L/usr/x11/lib -lmlx -lXext -lX11
	@make clean

test:
	@gcc -c -g $(CFLAG) $(SOURCE)
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
