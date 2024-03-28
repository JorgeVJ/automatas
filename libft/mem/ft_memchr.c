/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:39:47 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/11 16:44:10 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	*aux;
	unsigned char	n;

	i = 0;
	aux = (unsigned char *)str;
	n = (unsigned char)c;
	while (size > i)
	{
		if (aux[i] == n)
			return ((void *)aux + i);
		i++;
	}
	return (0);
}
