make -C libft/ fclean
make -C libft
make -C libft/ clean
gcc -o test1 test1.c ./libft/libft.a -L/usr/x11/lib -lmlx -lXext -lX11
./test1