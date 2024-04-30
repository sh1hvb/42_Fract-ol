/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:52:29 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/29 21:57:54 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	handle_events(t_fract *fract)
{
	// mlx_hook(fract->mlx_win, MotionNotify, PointerMotionMask, onmove, fract);
	mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, onpress, fract);
	mlx_hook(fract->mlx_win, ButtonPress, ButtonPressMask, onclick, fract);
	mlx_hook(fract->mlx_win, DestroyNotify, StructureNotifyMask, close_win,
			fract);
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



int onclick(int button, int x, int y, t_fract *fract)
{
    (void)x;
    (void)y;
    
    if (button == Button4) // Zoom in
    {
        // Calculate the new range after zooming in
        fract->zoom *=0.95;
    }
	
    else if (button == Button5) // Zoom out
    {
        fract->zoom *=1.05;
    }
    fract_ren(fract);
        
    
    return (0);
}

// #include <stdio.h>

// typedef struct {
//     double zoom;
//     // Other members of t_fract
// } t_fract;

// int onclick(int button, int x, int y, t_fract *fract)
// {
//     // Adjust zoom based on mouse position
//     double zoom_factor = 0.05; // You can adjust this factor as needed
    
//     if (button == Button4) // Zoom in
//     {
//         fract->zoom *= (1.0 - zoom_factor);
//         fract->zoom_x += (x - fract->width / 2) * zoom_factor;
//         fract->zoom_y += (y - fract->height / 2) * zoom_factor;
//     }
//     else if (button == Button5) // Zoom out
//     {
//         fract->zoom *= (1.0 + zoom_factor);
//         fract->zoom_x -= (x - fract->width / 2) * zoom_factor;
//         fract->zoom_y -= (y - fract->height / 2) * zoom_factor;
//     }

//     fract_ren(fract); // Render fractal with new zoom
//     return (0);
// }



// int	julia_set(int x, int y, t_fract *fract)
// {
// 	if (!ft_strncmp("julia", fract->name, 5) || ft_strncmp("mandelbrot",
// 			fract->name, 10))
// 	{
// 		fract->julia_x = (scale(x, -2, +2, 800) * fract->zoom)
// 			+ fract->shift_x;
// 		fract->julia_y = (scale(y, +2, -2, 800) * fract->zoom)
// 			+ fract->shift_y;
// 		fract_ren(fract);
// 	}
// 	return (0);
// }