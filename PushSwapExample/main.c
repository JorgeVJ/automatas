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

#include "automata.h"

void	printtree(void *data)
{
	printf("%d\n", *(int *)(data));
}

int main() {
	t_automata  a;
	t_data		info;

	ft_bzero(&a, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));
	alphabet_init(&a);
	errors_init(&a);
	sactions_init(&a);
	a.statelen = 5;
	tactions_init(&a);
	a.str = ft_strdup("  0 1 -123 45 42   -4 31 -24 1 0 -849 43 154 67 54 81 29 5");
	evaluate(&a, &info);
	
	tree_in_order(info.numbers, printtree);
	return (0);
}