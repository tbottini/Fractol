/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:56 by tbottini          #+#    #+#             */
/*   Updated: 2019/03/12 14:33:41 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 100000

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_mtrc
{
	int				len_y;
	int				len_x;
	int				*num;
}					t_mtrc;

t_mtrc				*matrice_new(int len_x, int len_y, int *nums);
t_mtrc				*matrice_null(int len_x, int len_y);
void				matrice_del(t_mtrc **mtrc);
t_mtrc				*mtrc_calc(t_mtrc *m1, t_mtrc *m2,
					int (*f)(t_mtrc*, t_mtrc*, int, int));
void				matrice_print(t_mtrc *mtrc);
int					matrice_mul(t_mtrc *mtrc1, t_mtrc *mtrc2, int dx, int dy);
int					matrice_sub(t_mtrc *mtrc1, t_mtrc *mtrc2, int dx, int dy);
int					matrice_add(t_mtrc *mtrc1, t_mtrc *mtrc2, int dx, int dy);
void				*ft_error_null(char *msg);
void				ft_print_dtc_nb(char **dtc, int size_x);
int					ft_error(int ret_value, char *msg);
char				**ft_new_cdt(int x, int y);
int					get_next_line(int fd, char **line);
char				*ft_get_file(int fd);
char				*ft_strndup(const char *s1, int len);
void				ft_bzero(void *s, size_t n);
void				ft_putnbrcr(int nbr);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin_free(char *s1, char *s2, char option);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_max_compare(const char *nbr, int sign);
void				ft_print_tab(char **tab);
t_list				*ft_lstaddlast(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
char				*ft_strrev(char *str);
void				ft_swap(char *a, char *b);
int					ft_pow(int nb, int pow);

#endif
