# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 18:09:49 by yberramd          #+#    #+#              #
#    Updated: 2019/03/04 16:35:48 by tbottini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libft.a

INCLUDE 	=		-I /usr/local/include -I ../include

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

LIB 		=

SRCS		=		ft_isspace.c			\
					get_next_line.c 		\
					ft_error_null.c 		\
					matrice_sub.c 			\
					matrice_add.c 			\
					matrice_calc.c 			\
					matrice_print.c 		\
					matrice_del.c 			\
					matrice_new.c 			\
					matrice_null.c			\
					ft_print_dtc_nb.c 		\
					ft_error.c 				\
					ft_new_cdt.c 			\
					ft_get_file.c 			\
					ft_strjoin_free.c 		\
					ft_strndup.c			\
					ft_putnbrcr.c			\
					ft_isalnum.c			\
					ft_isalpha.c			\
					ft_bzero.c				\
					ft_isascii.c			\
					ft_isdigit.c			\
					ft_isprint.c			\
					ft_lstadd.c				\
					ft_lstaddlast.c			\
					ft_lstdel.c				\
					ft_lstiter.c			\
					ft_lstdelone.c			\
					ft_lstnew.c				\
					ft_lstmap.c				\
					ft_memccpy.c			\
					ft_memchr.c				\
					ft_memcpy.c				\
					ft_itoa.c				\
					ft_memcmp.c				\
					ft_memalloc.c		 	\
					ft_memdel.c				\
					ft_putchar.c			\
					ft_print_tab.c			\
					ft_putchar_fd.c			\
					ft_memmove.c			\
					ft_putendl.c			\
					ft_memset.c				\
					ft_putendl_fd.c			\
					ft_putstr_fd.c			\
					ft_putstr.c				\
					ft_putnbr.c				\
					ft_putnbr_fd.c			\
					ft_strclr.c				\
					ft_strcat.c				\
					ft_strchr.c				\
					ft_strdel.c				\
					ft_strcpy.c				\
					ft_strcmp.c				\
					ft_atoi.c 				\
					ft_strequ.c				\
					ft_strdup.c				\
					ft_striter.c			\
					ft_striteri.c			\
					ft_strlen.c				\
					ft_strjoin.c			\
					ft_strlcat.c			\
					ft_strncat.c			\
					ft_strmap.c				\
					ft_strnequ.c			\
					ft_strncpy.c			\
					ft_strnew.c				\
					ft_strmapi.c			\
					ft_strncmp.c			\
					ft_strrchr.c			\
					ft_strsub.c				\
					ft_strnstr.c			\
					ft_strstr.c				\
					ft_tolower.c			\
					ft_toupper.c			\
					ft_strsplit.c			\
					ft_strtrim.c 			\


OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o		:		%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME)	: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Compilation Libft Terminee"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
