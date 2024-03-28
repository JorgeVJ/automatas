/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_pre_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:17:21 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/18 20:17:21 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tree_pre_order(t_tree *tree, void (*ft)(void*))
{
	if (tree != NULL)
	{
		ft(tree->data);
		tree_pre_order(tree->left, ft);
		tree_pre_order(tree->right, ft);
	}
}
