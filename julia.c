/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:55:55 by mchihab           #+#    #+#             */
/*   Updated: 2024/05/05 12:03:47 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	if_julia(t_cmplx *z, t_cmplx *c, t_fract *fract)
{
	if (!ft_strncmp("julia", fract->name, 5))
	{
		c->x = fract->julia_x;
		c->y = fract->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	init_julia(t_fract *fract, char **av, int check)
{
	if (check == 0)
	{
		fract->julia_x = atodbl(av[2]);
		fract->julia_y = atodbl(av[3]);
	}
	else
	{
		fract->julia_x = -0.7269;
		fract->julia_y = 0.1889;
	}
}
