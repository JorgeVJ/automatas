/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:48:08 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/26 16:48:10 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

/* ************************************************************************** */
/*    This file will contain all the custom actions refered to the project    */
/* ************************************************************************** */

void	add_token(t_tree *tree, char *cmdline)
{
	if (!tree->left)
	{
		tree->left = tree_new_node(tree->data);
		tree->data = cmdline;
	}
	else if (!tree->right)
		tree->right = tree_new_node(cmdline);
	else
		add_token(tree->right, cmdline);
}

void	get_token(t_automata *a, void *data)
{
	char	*cmdline;
	t_data	*info;
	t_tree	*tree;

	info = (t_data *)data;
	cmdline = ft_substr(a->str, a->j, a->i - a->j);
	a->j = a->i;
	if (!info->tree)
		info->tree = tree_new_node(cmdline);
	else
		add_token(info->tree, cmdline);
}
