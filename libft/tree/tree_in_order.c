/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_in_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:17:08 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 21:42:40 by jvasquez         ###   ########.fr       */
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

void	tree_in_order_context(t_tree *tree, void (*ft)(void*, void*), void *context)
{
	if (tree != NULL)
	{
		tree_in_order_context(tree->left, ft, context);
		ft(tree->data, context);
		tree_in_order_context(tree->right, ft, context);
	}
}
