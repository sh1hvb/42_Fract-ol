/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:20 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/26 12:35:20 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int check_double(char *av)
{
	int i;
	int p;
	i = 0;
	p = 0;
	while(av[i])
	{
		if(av[i]== '-' || av[i]== '+')
			i++;
		if (av[i] == '.' && i != 0)
			p += 1;
		if((av[i] >= '0' && av[i] <= '9') || p == 1)
				i++;
		else 
			return 0;
	}
	return 1;
}
void	pixel_put_in(int x, int y, t_img *img, int color)
{
	int	of;

	of = (y * img->len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->p_pixels + of) = color;
}
void	handle_pix(int x, int y, t_fract *fract)
{
	t_cmplx	z;
	t_cmplx	c;
	int		i;
	int		rgb;

	i = 0;
	z.x = (scale(x, -2, +2, 800) * fract->zoom) + fract->shift_x;
	z.y = (scale(y, +2, -2, 800) * fract->zoom) + fract->shift_y;
	if_julia(&z, &c, fract);
	while (i < fract->iterations)
	{
		z = sum(square(z), c);
		if ((z.x * z.x) - (z.y * z.y) > fract->escaped)
		{
			rgb = colore(i,WHITE , BLACK, fract->iterations);
			pixel_put_in(x, y, &fract->img, rgb);
			return ;
		}
		++i;
	}
	pixel_put_in(x, y, &fract->img, DARK_BLUE);
}

void	fract_ren(t_fract *fract)
{
	int	x;
	int	y;

	// x = 0;
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			handle_pix(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_conn, fract->mlx_win, fract->img.img, 0,
			0);
}
int	main(int ac, char **av)
{
	t_fract fract;
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fract.name = av[1];

		if (ac == 4 && !ft_strncmp("julia", fract.name, 5))
		{
            if(check_double(av[2]) && check_double(av[3]))
            {
			    fract.julia_x = (double)atof(av[2]);
				// dprintf(2,"%f\n",atof(av[2]));
			    fract.julia_y = (double)atof(av[3]);
				// dprintf(2,"%f\n",atof(av[3]));
            }
            else
					ft_putendl_fd("please enter a correct value like '-0.04 +0.24' (real & imaginary)", 2) , exit(EXIT_FAILURE);

		}
		init_fract(&fract);
		fract_ren(&fract);
		mlx_loop(fract.mlx_conn);
	}
	else
	{
		ft_putendl_fd("please enter a correct value", 2);
		exit(1);
	}
}