/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:43:11 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/19 16:15:22 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	n;

	n = size * count;
	if (n < count || n < size)
		return (NULL);
	temp = malloc(n);
	if (temp == (void *)0)
		return (NULL);
	ft_bzero(temp, n);
	return (temp);
}
