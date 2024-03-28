/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:18:55 by jvasquez          #+#    #+#             */
/*   Updated: 2023/10/02 16:18:56 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrpos(char *str, int chr, int start)
{
	int	i;
	int	len;

	len = (int)ft_strlen(str);
	if (!str || chr < 0 || start < 0)
		return (-1);
	i = start - 1;
	while (++i < len && str[i])
		if (str[i] == chr)
			return (i);
	return (-1);
}
