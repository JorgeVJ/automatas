/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:28:09 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/19 14:28:10 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Return all the items in a array string joined and separated
//by the string given.
char	*ft_unsplit(char **sarr, char *sep)
{
	int		i;
	char	*unsplit;

	if (!sarr)
		return (NULL);
	unsplit = ft_strdup(sarr[0]);
	i = 0;
	while (sarr[++i])
	{
		if (!sep)
			unsplit = ft_strjoin(unsplit, sarr[i]);
		else
			unsplit = ft_strjoin(unsplit, ft_strjoin(sep, sarr[i]));
	}
	return (unsplit);
}
