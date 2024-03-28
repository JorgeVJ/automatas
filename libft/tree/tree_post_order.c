/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_post_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:17:16 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/18 20:17:16 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tree_post_order(t_tree *tree, void (*ft)(void*))
{
	if (tree != NULL)
	{
		tree_post_order(tree->left, ft);
		tree_post_order(tree->right, ft);
		ft(tree->data);
	}
}
