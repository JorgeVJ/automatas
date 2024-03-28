/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:08:39 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 23:49:53 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	printtree(void *data)
{
	t_token	*token;

	token = (t_token *)data;
	printf("line: %s\n", token->line);
	printf("cmd: %s\n", token->cmd);
	printf("infile: %s\n", token->infile);
	printf("outfile: %s\n", token->outfile);
    printf("args:\n");
	ft_sarrprint(token->args);
    printf("\n\n");
}

void	set_token_type(void *data)
{
	t_token	*token;

	token = (t_token *)data;
	if (ft_strlen(token->line) == 1 && token->line[0] == '|')
		token->type = TOK_OPR;
}