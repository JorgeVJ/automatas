/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mask_and.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:52:19 by jvasquez          #+#    #+#             */
/*   Updated: 2023/01/31 20:52:21 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Checks if every bit in "with" is in the same state in "mask".
int	check_mask_and(int mask, int with)
{
	if ((mask & with) == with)
		return (1);
	return (0);
}
