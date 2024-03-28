/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ainit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:39 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 20:07:46 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

/**
 * 	Alphabet definitions
**/
void	alphabet_init(t_automata *a)
{
	a->alphabet = ft_sarradd(NULL, " ");
	a->alphabet = ft_sarradd(a->alphabet, "-");
	a->alphabet = ft_sarradd(a->alphabet, "0123456789");
}

int	get_state(int i, int j)
{
	int states[][4] = {
	//  \s, -, D, ^
		{0, 1, 3, 2},   // Empty input
		{2, 2, 3, 2},   // Negative sign found
		{2, 2, 2, 2},   // Invalid Character
		{4, 2, 3, 2},   // Digit found
		{4, 1, 3, 2},   // Space after Digits
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
	a->errors = ft_sarradd(a->errors, "Negative sign without a number.");
	a->errors = ft_sarradd(a->errors, "Invalid characters");
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
	a->fta[DIGIT][SPACES_BTW] = getnum;
}
