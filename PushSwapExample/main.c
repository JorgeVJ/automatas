/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:51:13 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 20:07:42 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	printtree(void *data)
{
	printf("%d\n", *(int *)(data));
}

void	automata_init(t_automata *a, void *data)
{
	alphabet_init(a);
	errors_init(a);
	sactions_init(a);
	tactions_init(a);
	a->data = data;
	a->get_state = get_state;
}

int	main(void)
{
	t_automata	a;
	t_data		info;

	ft_bzero(&a, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));
	automata_init(&a, &info);
	a.str = ft_strdup(" 0 1 -123 45 42 -4 31 -24 1 0 -849 54 81 29 5");
	evaluate(&a);
	tree_in_order(info.numbers, printtree);
	return (0);
}