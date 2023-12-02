/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ainit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:39 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/26 16:34:42 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

/**
 * 	Alphabet definitions
**/
void	alphabet_init(t_automata *a)
{
	a->alphabet = ft_sarradd(NULL, " ");
	a->alphabet = ft_sarradd(a->alphabet, "|");
	a->alphabet = ft_sarradd(a->alphabet, "<");
	a->alphabet = ft_sarradd(a->alphabet, ">");
	a->alphabet = ft_sarradd(a->alphabet, "&");
	a->alphabet = ft_sarradd(a->alphabet, "\"");
	a->alphabet = ft_sarradd(a->alphabet, "\'");
}

/**
 * 	Error strings to print when automata finish on a
 * 		non ending state.
**/
void	errors_init(t_automata *a)
{
	a->errors = NULL;
	a->errors = ft_sarradd(NULL, "Empty string.");
	a->errors = ft_sarradd(a->errors, "Open double quotes");
	a->errors = ft_sarradd(a->errors, "Open single quotes");
	a->errors = ft_sarradd(a->errors, "Pipe open");
	a->errors = ft_sarradd(a->errors, "Or open");
	a->errors = ft_sarradd(a->errors, "Less open");
	a->errors = ft_sarradd(a->errors, "Heredoc open");
	a->errors = ft_sarradd(a->errors, "Greater open");
	a->errors = ft_sarradd(a->errors, "Append open");
	a->errors = ft_sarradd(a->errors, "& Found");
	a->errors = ft_sarradd(a->errors, "And open");
	a->errors = ft_sarradd(a->errors, "Invalid input");
	a->errorlen = ft_sarrsize(a->errors);
}

/**
 *	Simple actions, they trigger when entering a state.
**/
void	sactions_init(t_automata *a)
{
}

/**
 *	Transition actions, they trigger when going
 * 		from one state to another.
**/
void	tactions_init(t_automata *a)
{
	a->fta[NOT_OPERATOR][PIPE] = get_token;
	a->fta[NOT_OPERATOR][LESS] = get_token;
	a->fta[NOT_OPERATOR][GREATER] = get_token;
	a->fta[NOT_OPERATOR][AMPER] = get_token;
	a->fta[SPACES_BTW][PIPE] = get_token;
	a->fta[SPACES_BTW][LESS] = get_token;
	a->fta[SPACES_BTW][GREATER] = get_token;
	a->fta[SPACES_BTW][AMPER] = get_token;
	a->fta[PIPE][SPACES_NW] = get_token;
	a->fta[OR][SPACES_NW] = get_token;
	a->fta[AND][SPACES_NW] = get_token;
	a->fta[LESS][SPACES_NW] = get_token;
	a->fta[HEREDOC][SPACES_NW] = get_token;
	a->fta[GREATER][SPACES_NW] = get_token;
	a->fta[APPEND][SPACES_NW] = get_token;
	a->fta[PIPE][NOT_OPERATOR] = get_token;
	a->fta[OR][NOT_OPERATOR] = get_token;
	a->fta[AND][NOT_OPERATOR] = get_token;
	a->fta[LESS][NOT_OPERATOR] = get_token;
	a->fta[HEREDOC][NOT_OPERATOR] = get_token;
	a->fta[GREATER][NOT_OPERATOR] = get_token;
	a->fta[APPEND][NOT_OPERATOR] = get_token;
}
