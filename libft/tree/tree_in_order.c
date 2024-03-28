/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_in_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:17:08 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/18 20:17:08 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tree_in_order(t_tree *tree, void (*ft)(void*))
{
	if (tree != NULL)
	{
		tree_in_order(tree->left, ft);
		ft(tree->data);
		tree_in_order(tree->right, ft);
	}
}
