# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonandri <jonandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 16:35:17 by jonandri          #+#    #+#              #
#    Updated: 2025/08/21 10:48:57 by jonandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= fractol.c ft_julia_if.c ft_julia.c ft_mandelbrot.c utils.c utils1.c utils2.c

OBJS=$(SRCS:.c=.o)

CC=gcc

MLX_LIB= ./minilibx-linux

FLAG_MLX= -lmlx -lX11 -lXext -lm -lz

CFLAGS= -Wall -Werror -Wextra

INC_LIB= -I./minilibx-linux

NAME= fractol

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_LIB)
	$(CC) $(CFLAGS) -L$(MLX_LIB) $(OBJS) $(FLAG_MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_LIB) -c $< -o $@

clean:
	make clean -C $(MLX_LIB)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
