/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:20 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/20 21:23:30 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int init_fract(t_fract *fract)
{
    
}

int main(int ac , char **av)
{
    t_fract fract;
    if(ac == 2 && ft_strcmp(av[1] , "mandelbrot") || ac == 4 && ft_strcmp(av[1],"julia"))
    {
        fract.name=av[1];
        init_fract(&fract);
        fract_ren(&fract);
        mlx_loop(fract.mlx_conn);
    }
    else    
    {
        ft_putendl_fd("please enter a correct value",stderr);
        exit(1);
    }
}