/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:08:39 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/30 13:09:22 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	print_outfiles(void *data)
{
	t_file *file;

	file = (t_file *)data;
	if (file->type == APPEND)
		printf("archivo para append: %s\n", file->name);
	if (file->type == WRITE)
		printf("archivo para write: %s\n", file->name);
}

void	printtree(void *data)
{
	t_token	*token;

	token = (t_token *)data;
	printf("line: %s\n", token->line);
	printf("cmd: %s\n", token->cmd);
	printf("infile:\n");
	ft_sarrprint(token->infile);
    printf("args:\n");
	ft_sarrprint(token->args);
	printf("outfiles:\n");
	ft_lstiter(token->outfiles, print_outfiles);
    printf("\n\n");
}

void	set_token_type(void *data)
{
	t_token	*token;

	token = (t_token *)data;
	if (ft_strlen(token->line) == 1 && token->line[0] == '|')
		token->type = TOK_OPR;
}