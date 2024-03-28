/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:26:55 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/18 17:22:06 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr_fd(char const *s, int fd)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = -1;
	if (s)
		while (s[++i])
			write(fd, &s[i], 1);
	return (i);
}
