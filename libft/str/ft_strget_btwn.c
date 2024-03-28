/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strget_btwn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:27:47 by jvasquez          #+#    #+#             */
/*   Updated: 2023/10/05 08:27:49 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Get the string between the chars given, if chars not found returns NULL.
*/
char	*ft_strget_btwn(char *str, int start, char ini, char end)
{
	char	*group;
	int		left;
	int		right;

	if (!str)
		return (NULL);
	group = NULL;
	left = ft_chrpos(str, ini, start);
	right = ft_chrpos(str, end, left + 1);
	if (left != -1 && right > left)
		group = ft_substr(str, left + 1, right - left - 1);
	return (group);
}
