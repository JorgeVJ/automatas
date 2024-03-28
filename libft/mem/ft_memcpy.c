/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:05:05 by jvasquez          #+#    #+#             */
/*   Updated: 2022/06/27 15:30:34 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			j;

	if (!src && !dest)
		return (NULL);
	j = 0;
	while (j < n)
	{
		((unsigned char *)dest)[j] = ((unsigned char *)src)[j];
		j++;
	}
	return (dest);
}
