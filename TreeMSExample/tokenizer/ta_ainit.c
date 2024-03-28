/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ta_ainit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:39 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 22:23:42 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../example.h"

/**
 * 	Alphabet definitions
**/
void	tokenizer_alphabet_init(t_automata *a)
{
	a->alphabet = ft_sarradd(NULL, " ");
	a->alphabet = ft_sarradd(a->alphabet, "|");
	a->alphabet = ft_sarradd(a->alphabet, "\"");
	a->alphabet = ft_sarradd(a->alphabet, "\'");
}

int	tokenizer_get_state(int i, int j)
{
	const int states[][8] = {
	//   \s, |, ", ', ^
		{ 0, 3, 1, 2, 7},   // 0 Empty input
		{ 1, 1, 6, 1, 1},   // 1 Open double quotes
		{ 2, 2, 2, 6, 2},   // 2 Open single quotes
		{ 5, 4, 4, 4, 7},   // 3 Pipe open
		{ 4, 4, 4, 4, 4},   // 4 Invalid input
		{ 5, 4, 1, 2, 7},   // 5 Spaces without words
		{ 6, 3, 1, 2, 7},   // 6 Spaces between words
		{ 6, 3, 1, 2, 7},   // 7 Not operators
	};
	return (states[i][j]);
}

/**
 * 	Error strings to print when automata finish on a
 * 		non ending state.
**/
void	tokenizer_errors_init(t_automata *a)
{
	a->errors = ft_sarradd(NULL, "Empty string.");
	a->errors = ft_sarradd(a->errors, "Open double quotes");
	a->errors = ft_sarradd(a->errors, "Open single quotes");
	a->errors = ft_sarradd(a->errors, "Pipe open");
	a->errors = ft_sarradd(a->errors, "Invalid input");
	a->errorlen = ft_sarrsize(a->errors);
}

/**
 *	Simple actions, they trigger when entering a state.
**/
void	tokenizer_sactions_init(t_automata *a)
{
	a->fsa[TA_INVALID] = tokenizer_print_error;
}

/**
 *	Transition actions, they trigger when going
 * 		from one state to another.
**/
void	tokenizer_tactions_init(t_automata *a)
{
	a->fta[TA_SPACES_NW][TA_PIPE] = get_token;
	a->fta[TA_SPACES_BTW][TA_PIPE] = get_token;
	a->fta[TA_NOT_OPERATOR][TA_PIPE] = get_token;
	a->fta[TA_PIPE][TA_NOT_OPERATOR] = get_token;
	a->fta[TA_PIPE][TA_SPACES_NW] = get_token;
}

/**
 * Initialize all the automata components 
**/
void	tokenizer_automata_init(t_automata *a, void *data)
{
	tokenizer_alphabet_init(a);
	tokenizer_errors_init(a);
	tokenizer_sactions_init(a);
	tokenizer_tactions_init(a);
	a->data = data;
	a->get_state = tokenizer_get_state;
}