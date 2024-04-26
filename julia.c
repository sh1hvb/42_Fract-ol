/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:55:55 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/26 10:56:16 by mchihab          ###   ########.fr       */
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