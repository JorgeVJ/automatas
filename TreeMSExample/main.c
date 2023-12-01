/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:51:13 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/26 18:51:17 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	printtree(void *data)
{
	printf("%s\n", (char *)data);
}

int	get_state(int i, int j)
{
	int states[][8] = {
	//   \s,  |,  <,  >,  &,  ",  ', ^
		{ 0, 11,  5, 11, 11,  1,  2, 14},   // 0  Empty input
		{ 1,  1,  1,  1,  1, 13,  1,  1},   // 1  Open double quotes
		{ 2,  2,  2,  2,  2,  2, 13,  2},   // 2  Open single quotes
		{12,  4,  5, 11, 11,  1,  2, 14},   // 3  Pipe open
		{12, 11,  5, 11, 11,  1,  2, 14},   // 4  Or open
		{12, 11,  6, 11, 11,  1,  2, 14},   // 5  Less open
		{12, 11, 11, 11, 11,  1,  2, 14},   // 6  Heredoc open
		{12, 11, 11,  8, 11,  1,  2, 14},   // 7  Greater open
		{12, 11, 11, 11, 11,  1,  2, 14},   // 8  Append open
		{12, 11, 11, 11, 10,  1,  2, 11},   // 9  & Found
		{12, 11,  5, 11, 11,  1,  2, 14},   // 10 And open
		{11, 11, 11, 11, 11, 11, 11, 11},   // 11 Invalid input
		{12, 11, 11, 11, 11,  1,  2, 14},   // 12 Spaces without words
		{13,  3,  5,  7,  9,  1,  2, 14},   // 13 Spaces between words
		{13,  3,  5,  7,  9,  1,  2, 14},   // 14 Not operators
	};
	return (states[i][j]);
}

void	automata_init(t_automata  *a)
{
	alphabet_init(a);
	errors_init(a);
	sactions_init(a);
	tactions_init(a);
	a->get_state = get_state;
}

int main() {
	t_automata  a;
	t_data		info;
	int 		finalstate;

	ft_bzero(&a, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));

	automata_init(&a);

	a.str = ft_strdup(" echo 'hola mundo' | cat | grep a > file1 && cat file1");
	printf("%s\n", a.str);

	finalstate = evaluate(&a, &info);
	if (finalstate > a.errorlen)
		get_token(&a, &info);
	else	
		printf("%s\n", a.errors[finalstate]);

	printf("Imprimir arbol\n");
	tree_in_order(info.tree, printtree);
	return (0);
}