/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:56 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/22 19:48:38 by tbottini         ###   ########.fr       */
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
# include "mlx.h"
# include <math.h>
# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"

# define BUFF_SIZE 100000
# define SCREEN_X 800
# define SCREEN_Y 800
# define PI 3.1415926535
# define KEY_W 		13
# define KEY_Y		16
# define KEY_U 		32
# define KEY_I 		34
# define KEY_H 		4
# define KEY_J		38
# define KEY_K		40
# define KEY_A 		0
# define KEY_S 		1
# define KEY_D 		2
# define KEY_Q 		12
# define KEY_E 		14
# define KEY_R 		15
# define KEY_F 		3
# define KEY_P		35
# define KEY_O		31
# define KEY_U		32
# define KEY_I		34
# define KEY_T 		17
# define KEY_G		5
# define KEY_CTRL 	256
# define KEY_SHIFT 	257
# define KEY_ESC	53
# define WHEEL_UP 	5
# define WHEEL_DOWN 4
# define RM_BUTTON	1
# define LM_BUTTON	2
# define KEY_1		 18
# define KEY_2		 19
# define KEY_3		 20
# define KEY_4		 21
# define KEY_5		 22
# define WHITE		color_rgb(255, 255, 255)
# define BLUE		color_rgb(0, 0, 255)
# define RED		color_rgb(255, 0, 0)
# define GREEN		color_rgb(0, 255, 0)
# define YELLOW		color_rgb(255, 255, 0)
# define PURPLE		color_rgb(255, 0, 255)
# define CYAN		color_rgb(0, 255, 255)
# define BLACK		color_rgb(0, 0, 0)
# define BEIGE		color_rgb(245, 245, 210)
# define PCHARRIE 	color_rgb(125, 0, 50)
# define FRATARDI 	color_rgb(75, 0, 15)

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

typedef struct		s_col
{
	unsigned int	c;
}					t_col;

typedef struct		s_vct2
{
	int				x;
	int				y;
}					t_vct2;

typedef struct		s_fvct2
{
	float			x;
	float			y;
}					t_fvct2;

typedef struct		s_vct3
{
	float			x;
	float			y;
	float			z;
}					t_vct3;

typedef struct		s_rmesh
{
	char			**wires;
	int				x;
	int				y;
	float			scale;
}					t_rmesh;

typedef	struct		s_world_obj
{
	t_vct3			*position;
	t_vct3			*rotation;
}					t_world_obj;

typedef struct		s_camera
{
	t_vct3			*position;
	t_vct3			*rotation;
	int				fov;
	char			proj;
}					t_camera;

typedef struct		s_color_stock
{
	t_col			color1;
	t_col			color2;
	int				color_s1;
	int				color_s2;
	t_col			color_stock[11];
}					t_color_stock;

typedef struct		s_mlx_data
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned		*screen;
	int				sx;
	int				sy;
}					t_mlx_data;

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
t_vct2				*vct2_new(int x, int y);
t_vct2				*vct2_value(t_vct2 *vct, int x, int y);
void				vct2_print(char *msg, t_vct2 vct);
t_vct3				*vct3_new(int x, int y, int z);
t_vct3				*vct3_value(t_vct3 *vct, int x, int y, int z);
void				vct3_print(char *info, t_vct3 vct);
t_vct3				*vct3_add(t_vct3 *vct1, t_vct3 *vct2);
t_vct3				*vct3_mul(t_vct3 *vct1, int mul);
t_vct3				*vct3_cpy(t_vct3 *vct1, t_vct3 *vct2);
t_vct3				*vct3_negate(t_vct3 *vct);
t_vct3				*vct3_rotation(t_vct3 *pos, t_vct3 rot);
t_vct3				*vct3_calc(t_vct3 *vct1, t_vct3 *vct2,
							int(*f)(int, int));
int					sub(int a, int b);
int					add(int a, int b);
int					divi(int a, int b);
int					mul(int a, int b);
t_camera			*camera_new(int fov);

void				camera_ajust(t_mlx_data *fdf);
void				*camera_del(t_camera *cam);
void				color_stock_set(t_color_stock *cs);
t_col				cs_color(t_color_stock cs, char color);
t_mlx_data			*mlx_data_get(char *screen_name, int sx, int sy);
int					input_cs(int input, t_color_stock *cs);
void				*mlx_data_close(t_mlx_data *fdf);
unsigned int		color_rgb(unsigned char r, unsigned char g,
							unsigned char b);
void				img_pixel(t_mlx_data *mlx, t_vct2 vct,
							unsigned int color);
void				img_trait(t_mlx_data *fdf, t_vct2 vct1, t_vct2 vct2,
							t_col col);
t_vct3				*model_to_world(t_vct3 local_pos, t_vct3 trans, t_vct3 rot,
							int sca);
t_vct2				*world_to_view(t_vct2 *cursor, t_mlx_data mlx, t_camera cam,
							t_vct3 w_pos);
int					mouse_motion(int x, int y, t_mlx_data *mlx, t_camera *cam);
int					wall_nb(int nb, int min, int max);
t_mlx_data			*mlx_data_connection(t_mlx_data *ml, char *name);

#endif
