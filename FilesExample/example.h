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

}	t_data;

typedef enum e_states
{
	EMPTY,
	INVALID,
	COMMENT,
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
	M_PLANE,
	M_SPHERE,
	M_CYLINDER,
	FOUND_ELEM
}	t_states;

/* Innit */
void	alphabet_init(t_automata *a);
void	errors_init(t_automata *a);
int		get_state(int i, int j);

/* Single Actions */
void	sactions_init(t_automata *a);
// void	count_player(t_automata *a, void *data);

/* Transition Actions */
void	tactions_init(t_automata *a);
void	ambient(t_automata *a, void *data);
void	camera(t_automata *a, void *data);
void	light(t_automata *a, void *data);
void	sphere(t_automata *a, void *data);
void	plane(t_automata *a, void *data);
void	cylinder(t_automata *a, void *data);
