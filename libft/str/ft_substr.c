/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:13:19 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/11 18:27:09 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	i;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str) || !*str)
		return (ft_strdup(""));
	if (ft_strlen(str) + 1 <= (len + start))
		len = ft_strlen(str) - start;
	temp = ft_calloc(sizeof(char), len + 1);
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < len)
		temp[i] = str[start + i];
	return (temp);
}
