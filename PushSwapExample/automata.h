/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:35:05 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/26 16:35:08 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_data
{
	t_tree	*numbers;
}	t_data;

typedef struct s_automata
{
	char	**alphabet;
	char    **errors;
	char	*str;
	int     state;
	int     ostate;
	int     errorlen;
	int     statelen;
	int		i;
	int		j;
	void	(*fsa[5])(struct s_automata *a, void *data);
	void	(*fta[5][5])(struct s_automata *a, void *data);
}	t_automata;

int		evaluate(t_automata *a, void *data);
void	alphabet_init(t_automata *a);
void	errors_init(t_automata *a);

/* Single Actions */
void	sactions_init(t_automata *a);
void	getnum(t_automata *a, void *data);

/* Transition Actions */
void	tactions_init(t_automata *a);
