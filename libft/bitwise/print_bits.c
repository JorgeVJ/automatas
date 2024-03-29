/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:02:24 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/24 20:02:25 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_bits(int n)
{
	int	i;

	i = 32;
	while (i--)
	{
		ft_printf("%d", (n >> i) & 1);
		if (!(i % 4))
			write(1, " ", 1);
	}
	write (1, "\n", 1);
}