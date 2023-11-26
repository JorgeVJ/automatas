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

#include "automata.h"

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
 * 		non finish state.
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
 *	Simple actions, they trigger when getting a certain state. 
**/
void	sactions_init(t_automata *a)
{
	a->fsa[2] = count_player;
	a->fsa[3] = count_exit;
	a->fsa[4] = count_collectible;
}

/**
 *	Transition actions, they trigger when going
 * 		from a certain state to another.
**/
void	tactions_init(t_automata *a)
{
	// a->fta[3][4] = getnum;
}
