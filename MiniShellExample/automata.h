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
	char	**tokens;
}	t_data;

typedef struct s_automata
{
	char	**alphabet;
	char    **errors;
	char	*str;
	int     state;
	int     ostate;
	int     errorlen;
	int		i;
	int		j;
	void	(*fsa[15])(struct s_automata *a, void *data);
	void	(*fta[15][15])(struct s_automata *a, void *data);
}	t_automata;

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
