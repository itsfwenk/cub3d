/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:27:36 by fli               #+#    #+#             */
/*   Updated: 2024/10/09 13:35:29 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	ft_atod_dec(const char *nptr)
{
	int		i;
	double	div_dec;
	double	decimals;

	i = 0;
	decimals = 0;
	div_dec = 1;
	while (nptr[i] != '.')
		i++;
	i++;
	while (nptr [i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			decimals = decimals * 10;
			decimals = decimals + (nptr[i++] - '0');
			div_dec = div_dec * 10;
		}
	}
	return (decimals / div_dec);
}

double	ft_atod(const char *nptr)
{
	int		i;
	double	nbr;
	int		sign;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	nbr = 0;
	while (nptr [i] != '.' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			nbr = nbr * 10;
			nbr = nbr + (nptr[i++] - '0');
		}
	}
	return (sign * (nbr + ft_atod_dec(nptr)));
}

// # include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	double nb = ft_atod(argv[1]);
// 	dprintf(2, "nb : %f\n", nb);
// }
