/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mask_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:52:31 by jvasquez          #+#    #+#             */
/*   Updated: 2023/01/31 20:52:32 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Checks if any bit in "with" is in mask.
int	check_mask_not(int mask, int with)
{
	if ((~mask & with) == with)
		return (1);
	return (0);
}
