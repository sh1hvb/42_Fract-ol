#include "fractol.h"


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
	int		rgb = 0;

	i = 0;
	z.x = scale(x, fract->x_min_map , fract->x_max_map , 800) + fract->shift_x;
	z.y = scale(y, fract->y_max_map , fract->y_min_map , 800) + fract->shift_y;
	if_julia(&z, &c, fract);
	while (i < fract->iterations)
	{
		z = sum(square(z), c);
		if ((z.x * z.x) - (z.y * z.y) > fract->escaped)	
		{
			rgb = calculate_color(i, fract->iterations);
			pixel_put_in(x, y, &fract->img, rgb);
			return ;
		}
		++i;
	}
	pixel_put_in(x, y, &fract->img, calculate_color(rgb,y << 16));
}

void	draw_sierpinski(t_fract *fract)
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
}

void	fract_ren(t_fract *fract)
{
	if (!ft_strncmp(fract->name, "triangle", 8))
		draw_sierpinski(fract);
	else
	{
		ft_putendl_fd("Invalid fractal name", 2);
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(fract->mlx_conn, fract->mlx_win, fract->img.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fract fract;
	if (( ac == 2 && !ft_strncmp(av[1],"triangle",8)) || (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || ((ac == 4 || ac ==2)
			&& !ft_strncmp(av[1], "julia", 5)) )
	{
		fract.name = av[1];

		if (!ft_strncmp("julia", fract.name, 5))
		{
            if(ac == 4 && check_double(av[2]) && check_double(av[3]))
            {
			    fract.julia_x = atodbl(av[2]);
			    fract.julia_y = atodbl(av[3]);
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
