/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:16 by mchihab           #+#    #+#             */
/*   Updated: 2024/05/05 12:07:33 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define ZOOM_SENSITIVITY 0.1f
# define MINIMUM_RANGE 0.001     
# define MAXIMUM_RANGE 90000000.0f

# define LIGHT_BROWN 0xFFE699 
# define MEDIUM_BROWN 0x996633 
# define DARK_BROWN 0x330000 
# define RESET 0x000000
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define YELLOW 0xFFFF00100
# define MAGENTA 0xFF00FF100
# define WHITE 0xFFFFFF
# define GRAY 0x808080 
# define LIGHT_GRAY 0xD3D3D3 
# define DARK_GRAY 0x696969 
# define SILVER 0xC0C0C0 
# define GOLD 0xFFD700 
# define ORANGE 0xFFA500 
# define PINK 0xFFC0CB 
# define PURPLE 0x800080 
# define LAVENDER 0xE6E6FA 
# define INDIGO 0x4B0082 
# define TEAL 0x008080 
# define AQUA 0x00FFFF 
# define DARK_BLUE 0x00008B 
# define DARK_GREEN 0x006400 
# define DARK_RED 0x8B0000 
# define DARK_ORANGE 0xFF8C00 
# define DARK_PURPLE 0x800080 
# define DARK_CYAN 0x008B8B 

typedef struct s_cmplx
{
	double		x;
	double		y;
}				t_cmplx;

typedef struct s_img
{
	void		*img;
	char		*p_pixels;
	int			bpp;
	int			endian;
	int			len;

}				t_img;

typedef struct s_fract
{
	void		*mlx_conn;
	void		*mlx_win;
	char		*name;
	t_img		img;
	double		escaped;
	int			iterations;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		zoom_x;
	double		zoom_y;
	long double	x_min_map;
	long double	x_max_map;
	long double	y_max_map;
	long double	y_min_map;
	long double	ratio_x;
	long double	ratio_y;
	double		julia_x;
	double		julia_y;
}				t_fract;

void			init_data(t_fract *fract);
void			init_fract(t_fract *fract);
void			if_julia(t_cmplx *z, t_cmplx *c, t_fract *fract);
void			handle_events(t_fract *fract);
int				onpress(int keysim, t_fract *fract);
int				close_win(t_fract *fract);
int				onclick(int button, int x, int y, t_fract *fract);
t_cmplx			sum(t_cmplx z1, t_cmplx z2, char *name);
void			pixel_put_in(int x, int y, t_img *img, int color);
t_cmplx			square(t_cmplx z, char *name);
double			scale(double unum, double new_min, double new_max,
					double old_max);
void			init_julia(t_fract *fract, char **av, int check);
void			fract_ren(t_fract *fract);
int				calculate_color(int iteration, int max_iterations);
double			atodbl(const char *s);

#endif
