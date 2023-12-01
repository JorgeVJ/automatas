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

void	numtotree(t_data *data, t_tree *tree, int n)
{
	int		*num;

	num = malloc(sizeof(int));
	*num = n;
	if (!tree)
		data->numbers = tree_new_node(num);
	else if (*(int *)(tree->data) == n)
		printf("Numero duplicado %d\n",n);
	else if (*(int *)(tree->data) < n && tree->right == NULL)
		tree->right = tree_new_node(num);
	else if (*(int *)(tree->data) > n && tree->left == NULL)
		tree->left = tree_new_node(num);
	else if (*(int *)(tree->data) < n)
		numtotree(data, tree->right, n);
	else if (*(int *)(tree->data) > n)
		numtotree(data, tree->left, n);
}

void	getnum(t_automata *a, void *data)
{
	int		numint;
	char	*numstr;
	t_tree	*tree;

	tree = (t_tree *)((t_data *)data)->numbers;
	if (a->i > a->j)
	{
		numstr = ft_substr(a->str, a->j, a->i - a->j + 1);
		a->j = a->i;
		numint = ft_atoi(numstr);
		free (numstr);
		numtotree((t_data *)data, tree, numint);
	}
}
