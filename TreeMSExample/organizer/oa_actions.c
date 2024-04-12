/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oa_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:48:08 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/30 13:08:28 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../example.h"

/* ************************************************************************** */
/*    This file will contain all the custom actions refered to the project    */
/* ************************************************************************** */

/* Organize the cmd, the args, infile and outfile from the line into the token */
void	organize_token(t_automata *a, void *data)
{
	char	*substr;
	char	*trim;
	t_data	*info;
	t_token	*token;

	info = (t_data *)data;
	token = info->ctoken;
	if (token->type == TOK_OPR)
	{	// If token is an operator there's nothing to do
		return ;
	}

	if (a->str[a->i] == '\'' || a->str[a->i] == '\"')
		substr = ft_substr(a->str, a->j, a->i - a->j + 1);
	else
		substr = ft_substr(a->str, a->j, a->i - a->j);
	trim = ft_strtrim(substr, " ");
	free (substr);

	if (check_bit(info->memory, MEM_HEREDOC))
	{	// If HEREDOC have been readed, the substring is assigned to infile
		token->infile = ft_sarradd(token->infile, ft_strdup("HeredocFileName"));
		set_bit(&info->memory, MEM_HEREDOC, 0);
		set_bit(&info->memory, MEM_LOWER, 0);
		set_bit(&info->memory, REDIR_TAKEN, 1);
	}
	if (check_bit(info->memory, MEM_LOWER))
	{	// If LOWER have been readed, the substring is assigned to infile
		token->infile = ft_sarradd(token->infile, trim);
		set_bit(&info->memory, MEM_LOWER, 0);
		set_bit(&info->memory, REDIR_TAKEN, 1);
	}
	if (check_bit(info->memory, REDIR_TAKEN))
		set_bit(&info->memory, REDIR_TAKEN, 0);
	else if (check_bit(info->memory, MEM_APPEND))
	{	// If APPEND have been readed, the substring is assigned to outfile
		t_file *file;
		file = malloc(sizeof(t_file));
		file->name = ft_strdup(trim);
		file->type = APPEND;
		ft_lstadd_back(&token->outfiles, ft_lstnew(file));
		set_bit(&info->memory, MEM_APPEND, 0);
		set_bit(&info->memory, MEM_GREATER, 0);
	}
	else if (check_bit(info->memory, MEM_GREATER))
	{	// If GREATER have been readed, the substring is assigned to outfile
		t_file *file;
		file = malloc(sizeof(t_file));
		file->name = ft_strdup(trim);
		file->type = WRITE;
		ft_lstadd_back(&token->outfiles, ft_lstnew(file));
		set_bit(&info->memory, MEM_GREATER, 0);
	}
	else if (!check_bit(info->memory, CMD_TAKEN))
	{	// Check if the command has been taken
		token->cmd = ft_strdup(trim);
		token->args = ft_sarradd(token->args, trim);
		set_bit(&info->memory, CMD_TAKEN, 1);
		printf("CMD: %s\n", token->cmd);
	}
	else if (check_bit(info->memory, CMD_TAKEN))
	{	// Take the substr as argument
		token->args = ft_sarradd(token->args, trim);
	}
	a->j = a->i;
	free (trim);
}

/* Saves the operators are not neede so this function save the current operator in memory */
void save_in_memory(t_automata *a, void *data)
{
	t_data	*info;

	info = (t_data *)data;
	if (a->state == OA_LOWER)
		set_bit(&info->memory, MEM_LOWER, 1);
	else if (a->state == OA_HEREDOC)
		set_bit(&info->memory, MEM_HEREDOC, 1);
	else if (a->state == OA_GREATER)
		set_bit(&info->memory, MEM_GREATER, 1);
	else if (a->state == OA_APPEND)
		set_bit(&info->memory, MEM_APPEND, 1);
	a->j = a->i;
}

/* Skip the operator */
void skip_op(t_automata *a, void *data)
{
	a->j = a->i;
}

/* A function to be executed when falling into INVALID state */
void	organizer_print_error(t_automata *a, void *data)
{
	printf("Error found at pos: %d", a->i);
	exit(EXIT_FAILURE);
}
