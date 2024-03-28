/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:48:58 by jvasquez          #+#    #+#             */
/*   Updated: 2023/01/20 16:49:00 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Free one string array
void	ft_sarrfree(char ***arr)
{
	int	i;

	if (!arr || !arr[0])
		return ;
	i = -1;
	while (arr[0][++i])
	{
		if (arr[0][i])
		{
			free(arr[0][i]);
			arr[0][i] = NULL;
		}
	}
	free (*arr);
	*arr = NULL;
}
