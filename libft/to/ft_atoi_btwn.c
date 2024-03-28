/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_btwn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:27:01 by jvasquez          #+#    #+#             */
/*   Updated: 2023/10/05 08:27:03 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Get a string inside the chars given and return
 *  the integer of char numbers in the string.
*/
int	ft_atoi_btwn(char *str, char ini, char end)
{
	char	*number;
	int		n;

	number = ft_strget_btwn(str, 0, ini, end);
	if (number)
		n = atoi(number);
	else
		n = 0;
	free (number);
	return (n);
}
