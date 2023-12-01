/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:17:13 by jvasquez          #+#    #+#             */
/*   Updated: 2023/12/01 09:17:14 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../automata/automata.h"

typedef struct s_data
{
	char	**tokens;
}	t_data;

typedef enum e_states
{
	EMPTY,
	DQUOTES,
	SQUOTES,
	PIPE,
	OR,
	LESS,
	HEREDOC,
	GREATER,
	APPEND,
	AMPER,
	AND,
	INVALID,
	SPACES_NW,
	SPACES_BTW,
	NOT_OPERATOR
}	t_tokens;

int		evaluate(t_automata *a, void *data);
void	alphabet_init(t_automata *a);
void	errors_init(t_automata *a);

/* Single Actions */
void	sactions_init(t_automata *a);
void	get_token(t_automata *a, void *data);
// void	count_player(t_automata *a, void *data);

/* Transition Actions */
void	tactions_init(t_automata *a);
