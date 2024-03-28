/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:18:15 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/13 10:32:19 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	j;
	char	*csrc;
	char	*cdest;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (dest == src)
		return (dest);
	else if (dest < src)
	{
		j = 0;
		while (j < n)
		{
			cdest[j] = csrc[j];
			j++;
		}
	}
	else
		while (n--)
			cdest[n] = csrc[n];
	return (dest);
}
