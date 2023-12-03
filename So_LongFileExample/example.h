/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:04:39 by jvasquez          #+#    #+#             */
/*   Updated: 2023/12/01 09:04:40 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../automata/automata.h"

typedef struct s_data
{
	int		player_count;
	int		exit_count;
	int		collect_count;
	char	**map;
}	t_data;

typedef enum e_states
{
	EMPTY,
	INVALID,
	FOUND_P,
	FOUND_E,
	FOUND_C,
	FOUND_0,
	FOUND_FIRST,
	FOUND_MID,
	FOUND_END,
}	t_states;

void	alphabet_init(t_automata *a);
void	errors_init(t_automata *a);
int		get_state(int i, int j);

/* Single Actions */
void	sactions_init(t_automata *a);
void	count_player(t_automata *a, void *data);
void	count_exit(t_automata *a, void *data);
void	count_collectible(t_automata *a, void *data);

void	print_empty(t_automata *a, void *data);
void	print_wall(t_automata *a, void *data);
void	print_exit(t_automata *a, void *data);
void	print_collectible(t_automata *a, void *data);

/* Transition Actions */
void	tactions_init(t_automata *a);
