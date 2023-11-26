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

int states[][4] = {
//  \s, -, D, ^
	{0, 1, 3, 2},   // Empty input
	{2, 2, 3, 2},   // Negative sign found
	{2, 2, 2, 2},   // Invalid Character
	{4, 2, 3, 2},   // Digit found
	{4, 1, 3, 2},   // Space after Digits
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
