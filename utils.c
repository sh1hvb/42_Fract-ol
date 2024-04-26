/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:58:19 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/26 12:39:34 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int colore(int i, int start_color, int end_color, int iterations)
 {
    // Calculate the color increments
    float delta_color = (float)(end_color + start_color) / iterations;
    
    // Calculate the color for the given iteration
    int result = (int)(start_color + delta_color * i);
    
    return result;
}

t_cmplx	sum(t_cmplx z1, t_cmplx z2)
{
	t_cmplx	r;

	r.x = z1.x + z2.x;
	r.y = z1.y + z2.y;
	return (r);
}

t_cmplx	square(t_cmplx z)
{
	t_cmplx	r;

	r.x = (z.x * z.x) - (z.y * z.y);
	r.y = 2 * z.x * z.y;
	return (r);
}

double	scale(double unum, double new_min, double new_max,
		double old_max)
{
	return ((new_max - new_min) * (unum ) / (old_max)
		+ new_min);
}
double	atodbl(const char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign *= -1;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}