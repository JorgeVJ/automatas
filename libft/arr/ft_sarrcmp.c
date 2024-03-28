/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:27:15 by jvasquez          #+#    #+#             */
/*   Updated: 2023/01/20 19:27:16 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Compare a string with all the items in the array
return the index or -1 if there's no match*/
int	ft_sarrcmp(char **arr, char *str)
{
	int	i;

	if (!str || !arr)
		return (-1);
	i = -1;
	while (arr[++i])
	{
		if (!ft_strncmp(arr[i], str, ft_strlen(str)))
			return (i);
	}
	return (-1);
}
