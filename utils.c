/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:58:19 by mchihab           #+#    #+#             */
/*   Updated: 2024/05/05 12:04:51 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmplx	sum(t_cmplx z1, t_cmplx z2, char *name)
{
	t_cmplx	r;

	(void)name;
	r.x = (z1.x + z2.x);
	r.y = (z1.y + z2.y);
	return (r);
}

t_cmplx	square(t_cmplx z, char *name)
{
	t_cmplx	r;

	if (!ft_strncmp(name, "burning_ship", 8))
	{
		r.x = fabs((z.x * z.x - z.y * z.y));
		r.y = fabs((2 * z.x * z.y));
	}
	else
	{
		r.x = (z.x * z.x) - (z.y * z.y);
		r.y = 2 * z.x * z.y;
	}
	return (r);
}

double	scale(double unum, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unum) / (old_max) + new_min);
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

int	calculate_color(int iteration, int max_iterations)
{
	unsigned int	seed;
	unsigned int	rand_state;
	unsigned int	random_number;
	unsigned int	color;

	seed = iteration * 1337 + max_iterations;
	rand_state = seed;
	random_number = (1101 * rand_state + 12345) % 16777216;
	color = (random_number & 0xFFFFFF);
	return (color);
}
