/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:42:46 by jvasquez          #+#    #+#             */
/*   Updated: 2022/06/28 13:14:03 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_exp(int base, int exp)
{
	long int	sol;

	sol = base;
	while (--exp)
		sol = sol * base;
	return (sol);
}

static char	*ft_ini(char *num, long int *n, int *digits)
{
	if (*n < 0)
	{
		*digits += 1;
		*n *= -1;
		num = malloc(*digits + 1);
		if (!num)
			return (NULL);
		num[0] = '-';
	}
	else
	{
		num = malloc(*digits + 1);
		if (!num)
			return (NULL);
		num[0] = '0';
	}
	num[*digits] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	int			digits;
	int			i;
	long int	cn;
	char		*num;

	cn = n;
	digits = 1;
	while (cn / (ft_exp(10, digits)))
		digits++;
	num = NULL;
	num = ft_ini(num, &cn, &digits);
	if (!num)
		return (NULL);
	i = 0;
	while (cn)
	{
		num[digits - ++i] = '0' + cn % 10;
		cn = cn / 10;
	}
	return (num);
}
