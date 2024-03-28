/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:13:59 by jvasquez          #+#    #+#             */
/*   Updated: 2022/06/21 19:59:10 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen((char *)src);
	if (d_len > dsize || dsize == 0)
		return (s_len + dsize);
	i = 0;
	while (((unsigned char *)src)[i] && d_len + i < (dsize - 1))
	{
		dest[i + d_len] = ((unsigned char *)src)[i];
		i++;
	}
	dest[i + d_len] = '\0';
	return (d_len + s_len);
}
