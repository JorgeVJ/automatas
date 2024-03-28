/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ta_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:48:08 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 22:05:49 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../example.h"

/* ************************************************************************** */
/*    This file will contain all the custom actions refered to the project    */
/* ************************************************************************** */

/* Reserve memory for the new token */
t_token	*new_token(char *cmdline)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	ft_bzero(token, sizeof(t_token));
	token->line = cmdline;
	return token;
}

/* Adds a token to the tree, so it can be execute inorder */
void	add_token(t_tree *tree, char *cmdline)
{
	if (!tree->left)
	{
		tree->left = tree_new_node(tree->data);
		tree->data = new_token(cmdline);
	}
	else if (!tree->right)
		tree->right = tree_new_node(new_token(cmdline));
	else
		add_token(tree->right, cmdline);
}

/* Get the cmd line between pipes and also get the pipe into a new token */
void	get_token(t_automata *a, void *data)
{
	char	*cmdline;
	char	*trim;
	t_data	*info;
	t_tree	*tree;

	info = (t_data *)data;
	cmdline = ft_substr(a->str, a->j, a->i - a->j);
	trim = ft_strtrim(cmdline, " ");
	free (cmdline);
	a->j = a->i;
	if (!info->tree)
		info->tree = tree_new_node(new_token(trim));
	else
		add_token(info->tree, trim);
}

/* A function to be executed when falling into INVALID state */
void	tokenizer_print_error(t_automata *a, void *data)
{
	printf("Error found at pos: %d", a->i);
	exit(EXIT_FAILURE);
}
