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

int states[][10] = {
//   \S,  |,  <,  >,  &,  ",  ', (, ),
	{ 0, 11, 11, 11, 11,  1,  2, 14, 15, 16},   // 0  Empty input
	{ 1,  1,  1,  1,  1, 13,  1, 14, 15,  1},   // 1  Open double quotes
	{ 2,  2,  2,  2,  2,  2, 13, 14, 15,  2},   // 2  Open single quotes
	{12,  4,  5, 11, 11,  1,  2, 14, 15, 16},   // 3  Pipe open
	{12, 11, 11, 11, 11,  1,  2, 14, 15, 16},   // 4  Or open
	{12, 11,  6, 11, 11,  1,  2, 14, 15, 16},   // 5  Less open
	{12, 11, 11, 11, 11,  1,  2, 14, 15, 16},   // 6  Heredoc open
	{12, 11, 11,  8, 11,  1,  2, 14, 15, 16},   // 7  Greater open
	{12, 11, 11, 11, 11,  1,  2, 14, 15, 16},   // 8  Append open
	{12, 11, 11, 11, 10,  1,  2, 14, 15, 11},   // 9  & Found
	{12, 11, 11, 11, 11,  1,  2, 14, 15, 16},   // 10 And open
	{11, 11, 11, 11, 11, 11, 11, 11, 11, 11},   // 11 Invalid input
	{12,  1,  1,  1,  1,  1,  2, 14, 15, 16},   // 12 Spaces without words
	{13,  3,  5,  7,  9,  1,  2, 14, 15, 16},   // 13 Spaces between words
	{12, 11, 11, 11, 11,  1,  2, 14, 15, 16},   // 14 Open parentheses
	{13,  3,  5,  7,  9,  1,  2, 14, 15, 16},   // 15 Close parentheses
	{13,  3,  5,  7,  9,  1,  2, 14, 15, 16},   // 16 Not operators
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
		// printf("char: %c state: %d\n", a->str[a->i], state);
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