# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 18:09:49 by yberramd          #+#    #+#              #
#    Updated: 2019/03/01 19:48:13 by tbottini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fractol

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

INCLUDE 	=		-I include -I /usr/include

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

OBJS		=		$(SRCS:.c=.o)

all			: 		$(NAME)

%.o			:		%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME)		:
	@make -C libft
	@echo "Compilation" $(NAME) "En Cours"
	@make compile


compile		:		$(OBJS)
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(OBJS)
	@echo "Compilation" $(NAME) "Terminee"

clean 		:
	@make clean -C libft
	@rm -rf $(OBJS)

fclean		:		clean
	@make fclean -C libft
	@rm -rf $(NAME)

debug 		:		$(OBJS)
	@make -C libft
	@$(CC) -g -o $(NAME) $(CFLAGS) $(SRCS) $(LIB)
	@echo a
segv 		:		$(OBJS)
	@make -C libft
	@$(CC) -g -fsanitize=address -o $(NAME) $(CFLAGS) $(SRCS) $(LIB)

re			:		fclean all

.PHONY: all clean flcean re debug segv start