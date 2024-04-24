/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:16 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/24 20:46:03 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>

#define RESET   0x000000
#define BLACK   0x000000
#define RED     0xFF0000
#define GREEN  0x00FF00
#define YELLOW  0xFFFF00
#define BLUE    0x0000FF
#define MAGENTA 0xFF00FF
#define CYAN    0x00FFFF
#define WHITE   0xFFFFFF
#define BLUE_COLOR_1 0x100
#define BLUE_COLOR_2 0x200
#define BLUE_COLOR_3 0x300
#define BLUE_COLOR_4 0x400
#define BLUE_COLOR_5 0x500
#define BLUE_COLOR_6 0x600
#define BLUE_COLOR_7 0x700
#define BLUE_COLOR_8 0x800
#define BLUE_COLOR_9 0x900
#define BLUE_COLOR_10 0xA00
#define BLUE_COLOR_11 0xB00
#define BLUE_COLOR_12 0xC00
#define BLUE_COLOR_13 0xD00
#define BLUE_COLOR_14 0xE00
#define BLUE_COLOR_15 0xF00
typedef struct s_cmplx
{
    double x;
    double y;
}t_cmplx;


typedef struct s_img
{
    void *img;
    char *p_pixels;
    int bpp;
    int endian;
    int len;

} t_img;

typedef struct s_fract
{
    void *mlx_conn;
    void *mlx_win;
    char *name;
    t_img img;
    double escaped;
    int iterations;
    double shift_x;
    double shift_y;
    double zoom;
    double julia_x;
    double julia_y;
} t_fract;

double	atodbl(const char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign *= -1;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

#endif
