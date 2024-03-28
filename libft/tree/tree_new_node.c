/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:17:01 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/18 20:17:02 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*tree_new_node(void	*data)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	ft_bzero(node, sizeof(t_tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
