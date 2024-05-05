/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:20 by mchihab           #+#    #+#             */
/*   Updated: 2024/05/05 11:58:07 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_double(char *av)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (av[i])
	{
		while (av[i] <= 32)
			i++;
		if (av[i] == '-' || av[i] == '+')
			i++;
		if (av[i] == '.' && i != 0)
			p += 1;
		if ((av[i] >= '0' && av[i] <= '9') || p == 1)
			i++;
		else
			return (0);
	}
	return (1);
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
	z.x = scale(x, -2, +2, 800) * fract->zoom + fract->shift_x;
	z.y = scale(y, +2, -2, 800) * fract->zoom + fract->shift_y;
	if_julia(&z, &c, fract);
	while (i < fract->iterations)
	{
		z = sum(square(z, fract->name), c, fract->name);
		if ((z.x * z.x) + (z.y * z.y) > fract->escaped)
		{
			rgb = calculate_color(i, fract->iterations);
			pixel_put_in(x, y, &fract->img, rgb);
			return ;
		}
		++i;
	}
	pixel_put_in(x, y, &fract->img, BLACK);
}

void	fract_ren(t_fract *fract)
{
	int	x;
	int	y;

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
	mlx_put_image_to_window(fract->mlx_conn, fract->mlx_win,
		fract->img.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fract	fract;

	if ((ac == 2 && !ft_strcmp(av[1], "burning_ship")) || (ac == 2
			&& !ft_strcmp(av[1], "mandelbrot")) || ((ac == 4 || ac == 2)
			&& !ft_strcmp(av[1], "julia")))
	{
		fract.name = av[1];
		if (!ft_strcmp("julia", fract.name))
		{
			if (ac == 4 && check_double(av[2]) && check_double(av[3]))
				init_julia(&fract, av, 0);
			else if (ac == 2)
				init_julia(&fract, av, 1);
			else
				ft_putendl_fd("incorrect value", 2);
		}
		init_fract(&fract);
		fract_ren(&fract);
		mlx_loop(fract.mlx_conn);
	}
	else
		ft_putendl_fd("values disponible (julia) (mandelbrot)\
		(burning_ship)", 2);
}
