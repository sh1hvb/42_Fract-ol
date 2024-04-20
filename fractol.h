/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:16 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/20 21:19:44 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>




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
} t_fract;

#endif
