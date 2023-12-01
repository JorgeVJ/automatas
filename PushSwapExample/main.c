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

int	get_state(int i, int j)
{
	int states[][4] = {
	//  \s, -, D, ^
		{0, 1, 3, 2},   // Empty input
		{2, 2, 3, 2},   // Negative sign found
		{2, 2, 2, 2},   // Invalid Character
		{4, 2, 3, 2},   // Digit found
		{4, 1, 3, 2},   // Space after Digits
	};
	return (states[i][j]);
}

void	printtree(void *data)
{
	printf("%d\n", *(int *)(data));
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

	ft_bzero(&a, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));

	automata_init(&a);

	a.str = ft_strdup("  0 1 -123 45 42   -4 31 -24 1 0 -849 43 154 67 54 81 29 5");
	evaluate(&a, &info);

	tree_in_order(info.numbers, printtree);
	return (0);
}