/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:41:30 by jvasquez          #+#    #+#             */
/*   Updated: 2022/06/17 19:04:52 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*cstr;

	cstr = (unsigned char *)str;
	i = -1;
	while (++i < len)
		cstr[i] = c;
	return (cstr);
}
