/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:16 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/22 20:46:00 by mchihab          ###   ########.fr       */
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
} t_fract;

#endif
