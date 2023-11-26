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

#include "automata.h"

int states[][6] = {
//   1, P, E, C, 0, ^
	{6, 1, 1, 1, 1, 1},   // 0 Empty input
	{1, 1, 1, 1, 1, 1},   // 1 Invalid Character
	{8, 2, 3, 4, 5, 1},   // 2 Character Found
	{8, 2, 3, 4, 5, 1},   // 3 Exit Found
	{8, 2, 3, 4, 5, 1},   // 4 Collectible Found
	{8, 2, 3, 4, 5, 1},   // 5 Blank Space found
	{7, 2, 3, 4, 5, 1},   // 6 First Wall
	{8, 2, 3, 4, 5, 1},   // 7 Mid Wall
	{8, 2, 3, 4, 5, 1},   // 8 End Wall
};

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
		state = states[state][idx(a->alphabet, a->str[a->i])];
		if (a->fsa[state])
			a->fsa[state](a, data);
		if (a->fta[a->ostate][state])
			a->fta[a->ostate][state](a, data);
		a->ostate = state;
	}
	if (state < a->errorlen)
	  printf("%s\n", a->errors[state]);
	return (state);
}
