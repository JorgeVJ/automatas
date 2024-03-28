/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_del_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:17:31 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/18 20:17:31 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tree_del_node(t_tree *node, void (*del)(void*))
{
	if (!node || !del)
		return ;
	del(node->data);
	free(node);
}
