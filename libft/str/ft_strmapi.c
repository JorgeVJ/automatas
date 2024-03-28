/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:58:47 by jvasquez          #+#    #+#             */
/*   Updated: 2022/06/24 14:38:00 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sptr;
	int		index;

	if (!s || !f)
		return (NULL);
	sptr = malloc(ft_strlen(s) + 1);
	if (!sptr)
		return (NULL);
	index = -1;
	while (s[++index])
		sptr[index] = f(index, s[index]);
	sptr[index] = '\0';
	return (sptr);
}
