# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 18:09:49 by yberramd          #+#    #+#              #
#    Updated: 2019/03/04 16:52:54 by tbottini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fractol

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

INCLUDE 	=		-I include

LIB 		=		libft/libft.a -L /usr/local/lib/ -lmlx\
					-framework OpenGL \
					-framework AppKit -lm

SRCS		=		src/fractol.c		\
					src/parseur.c		\
					src/input.c			\
					src/julia.c			\
					src/mandelbrot.c	\
					src/burningship.c	\
					src/tricolor.c		\
					src/vector2_value.c	\
					src/mlx_data_get.c	\


OBJS		=		$(SRCS:.c=.o)

all			: 		$(NAME)

%.o			:		%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME)		:		 include/libft.h include/fractol.h $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(OBJS)
	@echo "Compilation" $(NAME) "Terminee"

clean 		:
	@make clean -C libft
	@rm -rf $(OBJS)

fclean		:		clean
	@make fclean -C libft
	@rm -rf $(NAME)

start		:		all
	$(shell ./$(NAME) mandelbrot)

re			:		fclean all

.PHONY: all clean flcean re start
