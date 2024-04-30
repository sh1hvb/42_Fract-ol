/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:20 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/30 11:56:55 by mchihab          ###   ########.fr       */
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
		while(av[i] <= 32)
			i++;
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

int calculate_color(int iteration, int max_iterations) 
{
    unsigned int seed = 42; 
    seed = iteration * seed + max_iterations; 
    unsigned int rand_state = seed;
    int red = (1101 * rand_state + 12345) % 256;
    rand_state = 1101 * rand_state + 12345; 
    int green = (1101 * rand_state + 12345) % 256; 
    rand_state = 1101 * rand_state + 12345; 
    int blue = (1101 * rand_state + 12345) % 256; 

    int color = (red << 16) | (green << 8) | blue;

    return color;
}

void	handle_pix(int x, int y, t_fract *fract)
{
	t_cmplx	z;
	t_cmplx	c;
	int		i;
	// int		rgb = 0;

	i = 0;
	z.x = scale(x, -2, +2 , 800) * fract->zoom + fract->shift_x;
	z.y = scale(y, +2 , -2 , 800) * fract->zoom + fract->shift_y;
	if_julia(&z, &c, fract);
	while (i < fract->iterations)
	{
		z = sum(square(z, fract->name), c, fract->name);
		if ((z.x * z.x) + (z.y * z.y) > fract->escaped)	
		{
			// rgb = YELLOW;
			pixel_put_in(x, y, &fract->img, LIGHT_BROWN);
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
	if (( ac == 2 && !ft_strncmp(av[1],"burning_ship",8)) || (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || ((ac == 4 || ac ==2)
			&& !ft_strncmp(av[1], "julia", 5)) )
	{
		fract.name = av[1];

		if (!ft_strncmp("julia", fract.name, 5))
		{
            if(ac == 4 && check_double(av[2]) && check_double(av[3]))
            {
			    fract.julia_x = atodbl(av[2]);
				// dprintf(2,"%f\n",atof(av[2]));
			    fract.julia_y = atodbl(av[3]);
				// dprintf(2,"%f\n",atof(av[3]));
            }
            else
			{
				fract.julia_x = -0.7269 ;
				fract.julia_y=  0.1889;
			}		

		}
		init_fract(&fract);
		fract_ren(&fract);
		mlx_loop(fract.mlx_conn);
	}
	else
	{
		ft_putendl_fd("please enter a correct value like '-0.04 +0.24' (real & imaginary)", 2) , exit(EXIT_FAILURE);
		exit(1);
	}
}
// void calculate_burning_ship(t_cmplx *z, t_cmplx *c, t_fract *)
// {
//  int  i;
//  double x_temp;

//  fractal->name = "ship";
//  i = 0;
//  z->x = 0.0;
//  z->y = 0.0;
//  c->x = (fractal->x / fractal->zoom) + fractal->offset_x;
//  fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
//  while (++i < fractal->max_iterations)
//  {
//   x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
//    + fractal->cx;
//   fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
//   fractal->zx = fabs(x_temp);
//   if (fractal->zx * fractal->zx + fractal->zy
//    * fractal->zy >= __DBL_MAX__)
//    break ;
//  }
//  if (i == fractal->max_iterations)
//   put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
//  else
//   put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
//     * i));
// }