/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:09:03 by jvasquez          #+#    #+#             */
/*   Updated: 2023/12/01 09:09:04 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../automata/automata.h"

typedef struct s_data
{
	t_tree	*numbers;
}	t_data;

typedef enum e_states
{
	EMPTY,
	NEGATIVE,
	INVALID,
	DIGIT,
	SPACES_BTW
}	t_states;

void	alphabet_init(t_automata *a);
void	errors_init(t_automata *a);

/* Single Actions */
void	sactions_init(t_automata *a);
void	getnum(t_automata *a, void *data);

/* Transition Actions */
void	tactions_init(t_automata *a);