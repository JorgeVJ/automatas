/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oa_ainit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:39 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 23:33:09 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../example.h"

/**
 * 	Alphabet definitions
**/
void	organizer_alphabet_init(t_automata *a)
{
	a->alphabet = ft_sarradd(NULL, " ");
	a->alphabet = ft_sarradd(a->alphabet, "\"");
	a->alphabet = ft_sarradd(a->alphabet, "\'");
	a->alphabet = ft_sarradd(a->alphabet, "<");
	a->alphabet = ft_sarradd(a->alphabet, ">");
}

int	organizer_get_state(int i, int j)
{
	const int states[][8] = {
	//   \s, ", ', <, >, ^
		{ 0, 1, 2, 6, 8, 10},   // 0 Empty input
		{ 1, 5, 1, 1, 1,  1},   // 1 Open double quotes
		{ 2, 2, 5, 2, 2,  2},   // 2 Open single quotes
		{ 3, 3, 3, 3, 3,  3},   // 3 Invalid input
		{ 4, 1, 2, 6, 8, 10},   // 4 Spaces without words
		{ 5, 1, 2, 6, 8, 10},   // 5 Spaces between words
		{ 4, 1, 2, 7, 8, 10},   // 6 lower found
		{ 4, 1, 2, 3, 3, 10},   // 7 heredoc
		{ 4, 1, 2, 3, 9, 10},   // 8 greater found
		{ 4, 1, 2, 3, 3, 10},   // 9 append
		{ 5, 1, 2, 6, 8, 10},   // 10 Not operators
	};
	return (states[i][j]);
}

/**
 * 	Error strings to print when automata finish on a
 * 		non ending state.
**/
void	organizer_errors_init(t_automata *a)
{
	a->errors = ft_sarradd(NULL, "Empty string.");
	a->errors = ft_sarradd(a->errors, "Open double quotes");
	a->errors = ft_sarradd(a->errors, "Open single quotes");
	a->errors = ft_sarradd(a->errors, "Invalid input");
	a->errorlen = ft_sarrsize(a->errors);
}

/**
 *	Simple actions, they trigger when entering a state.
**/
void	organizer_sactions_init(t_automata *a)
{
	a->fsa[OA_INVALID] = organizer_print_error;
	a->fsa[OA_LOWER] = save_in_memory;
	a->fsa[OA_GREATER] = save_in_memory;
	a->fsa[OA_HEREDOC] = save_in_memory;
	a->fsa[OA_APPEND] = save_in_memory;
}

/**
 *	Transition actions, they trigger when going
 * 		from one state to another.
**/
void	organizer_tactions_init(t_automata *a)
{
	const int states = 11;
	int	state;

	state = -1;
	while (++state < states)
	{
		a->fta[OA_LOWER][state] = skip_op;
		a->fta[OA_GREATER][state] = skip_op;
		a->fta[OA_HEREDOC][state] = skip_op;
		a->fta[OA_APPEND][state] = skip_op;
		a->fta[OA_NOT_OPERATOR][state] = organize_token;
	}
		a->fta[OA_SQUOTES][OA_SPACES_BTW] = organize_token;
		a->fta[OA_DQUOTES][OA_SPACES_BTW] = organize_token;
		a->fta[OA_NOT_OPERATOR][OA_NOT_OPERATOR] = NULL;
}

/**
 * Initialize all the automata components 
**/
void	organizer_automata_init(t_automata *a, void *data)
{
	organizer_alphabet_init(a);
	organizer_errors_init(a);
	organizer_sactions_init(a);
	organizer_tactions_init(a);
	a->data = data;
	a->get_state = organizer_get_state;
}
