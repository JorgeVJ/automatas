/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:45:00 by jvasquez          #+#    #+#             */
/*   Updated: 2022/09/05 14:56:06 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putunsigned(unsigned long long nbr)
{
	return (pf_putnbr_base(nbr, "0123456789", 0));
}

int	pf_nbrlen(long int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 1;
	while (n && i++)
		n /= 10;
	return (--i);
}

size_t	pf_putptr(unsigned long long ptr)
{
	size_t	size;

	write(1, "0x", 2);
	size = pf_putnbr_base(ptr, "0123456789abcdef", 0) + 2;
	return (size);
}

int	pf_switchcase(va_list args, const char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = pf_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		size = pf_putstr_fd(va_arg(args, char *), 1);
	if (c == 'd')
		size = pf_putnbr_fd(va_arg(args, int), 1);
	if (c == 'i')
		size = pf_putnbr_fd(va_arg(args, int), 1);
	if (c == 'u')
		size = pf_putunsigned(va_arg(args, unsigned int));
	if (c == 'x')
		size = pf_putnbr_base(va_arg(args, int), "0123456789abcdef", 1);
	if (c == 'X')
		size = pf_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 1);
	if (c == 'p')
		size = pf_putptr(va_arg(args, unsigned long long));
	if (c == '%')
		size = write(1, "%", 1);
	return (size);
}

int	ft_printf(char const *str, ...)
{
	size_t	i;
	size_t	size;
	va_list	args;

	va_start(args, str);
	size = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			size += pf_switchcase(args, str[i + 1]);
			i += 2;
		}
		if (str[i] == '%')
			i--;
		else if (pf_strlen(str) > i)
			size += write(1, &str[i], 1);
	}
	va_end(args);
	return (size);
}
