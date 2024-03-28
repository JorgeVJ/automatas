/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:58:38 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/24 19:58:39 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Divide a string in two strings at the breakpoint
char	**ft_strbrk(char *str, int b_point)
{
	char	**half;
	int		len;

	half = NULL;
	len = ft_strlen(str);
	if (b_point >= len || b_point <= 0)
	{
		half = malloc(sizeof(char *) * 2);
		half[0] = ft_calloc(sizeof(char), len + 1);
		ft_strlcpy(half[0], str, len + 1);
		half[1] = NULL;
	}
	else
	{
		half = malloc(sizeof(char *) * 3);
		half[0] = ft_calloc(sizeof(char), b_point + 1);
		ft_strlcpy(half[0], str, b_point + 1);
		half[1] = ft_substr(str, b_point, len - b_point);
		half[2] = NULL;
	}
	return (half);
}
