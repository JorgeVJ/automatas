/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mask_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:52:26 by jvasquez          #+#    #+#             */
/*   Updated: 2023/01/31 20:52:27 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Checks if any bit in "with" is in mask.
int	check_mask_or(int mask, int with)
{
	if (mask & with)
		return (1);
	return (0);
}
