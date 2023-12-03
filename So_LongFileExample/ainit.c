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
	a->alphabet = ft_sarradd(NULL, "1");
	a->alphabet = ft_sarradd(a->alphabet, "P");
	a->alphabet = ft_sarradd(a->alphabet, "E");
	a->alphabet = ft_sarradd(a->alphabet, "C");
	a->alphabet = ft_sarradd(a->alphabet, "0");
	a->alphabet = ft_sarradd(a->alphabet, "\n");
}

int	get_state(int i, int j)
{
	const int	states[][7] = {
	//   1, P, E, C, 0,\n, ^
		{6, 1, 1, 1, 1, 1, 1},   // 0 Empty input
		{1, 1, 1, 1, 1, 1, 1},   // 1 Invalid Character
		{8, 2, 3, 4, 5, 1, 1},   // 2 Player Found
		{8, 2, 3, 4, 5, 1, 1},   // 3 Exit Found
		{8, 2, 3, 4, 5, 1, 1},   // 4 Collectible Found
		{8, 2, 3, 4, 5, 1, 1},   // 5 Blank Space found
		{7, 2, 3, 4, 5, 1, 1},   // 6 First Wall
		{8, 2, 3, 4, 5, 1, 1},   // 7 Mid Wall
		{8, 2, 3, 4, 5, 8, 1},   // 8 End Wall
	};

	return (states[i][j]);
}

/**
 * 	Error strings to print when automata finish on a
 * 		non ending state.
**/
void	errors_init(t_automata *a)
{
	a->errors = NULL;
	a->errors = ft_sarradd(NULL, "Empty string.");
	a->errors = ft_sarradd(a->errors, "Invalid character");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errorlen = ft_sarrsize(a->errors);
}

/**
 *	Simple actions, they trigger when entering a state.
**/
void	sactions_init(t_automata *a)
{
	a->fsa[FOUND_P] = count_player;
	a->fsa[FOUND_E] = count_exit;
	a->fsa[FOUND_C] = count_collectible;
}

/**
 *	Transition actions, they trigger when going
 * 		from one state to another.
**/
void	tactions_init(t_automata *a)
{
}
