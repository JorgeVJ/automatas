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
}

/**
 * 	Error strings to print when automata finish on a
 * 		non ending state.
**/
void	errors_init(t_automata *a)
{
	a->errors = NULL;
	a->errorlen = 8;
	a->errors = ft_sarradd(NULL, "Empty string.");
	a->errors = ft_sarradd(a->errors, "Invalid character");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
	a->errors = ft_sarradd(a->errors, "Non ending wall");
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
