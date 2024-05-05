/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:52:29 by mchihab           #+#    #+#             */
/*   Updated: 2024/05/05 12:03:23 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_events(t_fract *fract)
{
	mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, onpress, fract);
	mlx_hook(fract->mlx_win, ButtonPress, ButtonPressMask, onclick, fract);
	mlx_hook(fract->mlx_win, DestroyNotify, StructureNotifyMask,
		close_win, fract);
}

int	onpress(int keysim, t_fract *fract)
{
	if (keysim == XK_Escape)
		close_win(fract);
	if (keysim == XK_Left)
		fract->shift_x -= (0.5 * fract->zoom);
	else if (keysim == XK_Right)
		fract->shift_x += (0.5 * fract->zoom);
	else if (keysim == XK_Up)
		fract->shift_y += (0.5 * fract->zoom);
	else if (keysim == XK_Down)
		fract->shift_y -= (0.5 * fract->zoom);
	else if (keysim == XK_equal)
		fract->iterations += 10;
	else if (keysim == XK_minus)
		fract->iterations -= 10;
	fract_ren(fract);
	return (0);
}

int	close_win(t_fract *fract)
{
	mlx_destroy_image(fract->mlx_conn, fract->img.img);
	mlx_destroy_window(fract->mlx_conn, fract->mlx_win);
	mlx_destroy_display(fract->mlx_conn);
	free(fract->mlx_conn);
	exit(EXIT_SUCCESS);
	return (0);
}

int	onclick(int button, int x, int y, t_fract *fract)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fract->zoom *= 0.95;
	else if (button == Button5)
		fract->zoom *= 1.05;
	fract_ren(fract);
	return (0);
}
