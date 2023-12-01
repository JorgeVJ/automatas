/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:53:38 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/25 18:53:39 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "automata.h"

int idx(char *alphabet[], char c)
{
	int i;

	i = -1;
	while (alphabet[++i])
		if (ft_chrpos(alphabet[i], c, 0) != -1)
			return (i);
	return (i);
}

int evaluate(t_automata *a, void *data)
{
	int state = 0;

	a->ostate = 0;
	a->i = -1;
	while (++a->i < ft_strlen(a->str)) {
		state = a->get_state(state, idx(a->alphabet, a->str[a->i]));
		if (a->fsa[state])
			a->fsa[state](a, data);
		if (a->fta[a->ostate][state])
			a->fta[a->ostate][state](a, data);
		a->ostate = state;
	}
	return (state);
}
