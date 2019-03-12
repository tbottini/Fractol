/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:28:34 by tbottini          #+#    #+#             */
/*   Updated: 2019/03/12 14:33:54 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"

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

typedef struct		s_mlx_data
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned		*screen;
	int				sx;
	int				sy;
}					t_mlx_data;

typedef struct		s_ct
{
	int				select[3];
	uint8_t			color[9][3];
}					t_ct;

typedef struct		s_fractol
{
	t_mlx_data		*data;
	t_ct			*ct;
	uint32_t		(*fractal[3])(struct s_fractol*, t_vct2);
	float			zoom;
	int				imax;
	int				fnb;
	char			mouse_active;
	t_fvct2			mouse_pos;
	t_fvct2			pos;
}					t_fractol;

typedef struct		s_dvct2
{
	double			x;
	double			y;
}					t_dvct2;

t_fractol			*fractol_new();
int					fractol_parseur(int ac, char **av);
int					input_fractol(int key, t_fractol *fractol);
void				fractol_close(t_fractol *fractol);
int					each_pixel(t_fractol *fractol,
	uint32_t (*f)(t_fractol*, t_vct2));
uint32_t			julia(t_fractol *fctl, t_vct2 cur);
uint32_t			mandelbrot(t_fractol *fctl, t_vct2 cur);
int					mouse_const(int x, int y, t_fractol *fractol);
uint32_t			burningship(t_fractol *fctl, t_vct2 cur);
int					mouse_wheel(int key, int x, int y, t_fractol *fctl);
void				fractol_reinit(t_fractol *fractol);
uint32_t			fractol_degr(t_fractol *f, int i, int select);
void				ct_gestion(t_ct *ct, int key);
t_ct				*ct_get();
void				color_decomp(uint8_t rgb[3], unsigned int color);
void				fractol_reinit(t_fractol *fractol);
t_vct2				*vct2_value(t_vct2 *vct, int x, int y);
t_mlx_data			*mlx_data_get(char *screen_name, int sx, int sy);
void				*mlx_data_close(t_mlx_data *fdf);
unsigned int		color_rgb(unsigned char r, unsigned char g,
							unsigned char b);
void				img_pixel(t_mlx_data *mlx, t_vct2 vct,
							unsigned int color);
#endif
