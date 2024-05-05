/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:56:45 by mchihab           #+#    #+#             */
/*   Updated: 2024/05/03 15:28:14 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_fract *fract)
{
	fract->iterations = 32;
	fract->escaped = 4;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->zoom_x = 0.0;
	fract->zoom_y = 0.0;
	fract->zoom = 1.0;
	fract->x_min_map = -2;
	fract->x_max_map = 2;
	fract->y_max_map = 2;
	fract->y_min_map = -2;
}

void	init_fract(t_fract *fract)
{
	fract->mlx_conn = mlx_init();
	if (NULL == fract->mlx_conn)
		return ;
	fract->mlx_win = mlx_new_window(fract->mlx_conn, 800, 800, fract->name);
	if (fract->mlx_win == NULL)
		mlx_destroy_display(fract->mlx_conn);
	fract->img.img = mlx_new_image(fract->mlx_conn, 800, 800);
	fract->img.p_pixels = mlx_get_data_addr(fract->img.img, &fract->img.bpp,
			&fract->img.len, &fract->img.endian);
	init_data(fract);
	handle_events(fract);
}
