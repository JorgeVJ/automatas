/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:34:24 by jvasquez          #+#    #+#             */
/*   Updated: 2022/06/23 20:42:43 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	st_len;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	st_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(st_len);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, (char *)s1, st_len);
	ft_strlcat(joined, s2, st_len);
	return (joined);
}
