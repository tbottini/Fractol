/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:28:34 by tbottini          #+#    #+#             */
/*   Updated: 2019/03/04 16:44:45 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include "libft.h"

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
