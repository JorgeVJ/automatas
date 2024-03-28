/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:31:07 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/18 17:55:04 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = (long int)n;
	if (nbr < 0)
	{
		pf_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr > 9)
		pf_putnbr_fd(nbr / 10, fd);
	pf_putchar_fd((nbr % 10) + '0', fd);
	if (n < 0)
		return (pf_nbrlen(nbr) + 1);
	else
		return (pf_nbrlen(nbr));
}
