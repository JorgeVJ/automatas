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

void	automata_init(t_automata *a, void *data)
{
	alphabet_init(a);
	errors_init(a);
	sactions_init(a);
	tactions_init(a);
	a->data = data;
	a->get_state = get_state;
}

void	state_handle(t_automata *a, int state)
{
	if (a->state < a->errorlen)
	{
		printf("%s\n", a->errors[a->state]);
		exit (EXIT_FAILURE);
	}
	((t_data *)a->data)->map = ft_sarradd(((t_data *)a->data)->map, a->str);
}

int	main(void)
{
	t_automata	a;
	t_data		info;

	ft_bzero(&a, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));
	automata_init(&a, &info);
	evaluate_file(&a, "map.ber", state_handle);
	if (!info.player_count || !info.exit_count)
		exit (EXIT_FAILURE);
	printf("there are:\n%d player\n%d exit\n%d collectible\n",
		info.player_count, info.exit_count, info.collect_count);
	
	/* Changing actions to print background */
	a.fsa[FOUND_0] = print_empty;
	a.fsa[FOUND_P] = print_empty;
	a.fsa[FOUND_E] = print_exit;
	a.fsa[FOUND_C] = print_collectible;
	a.fsa[FOUND_FIRST] = print_wall;
	a.fsa[FOUND_MID] = print_wall;
	a.fsa[FOUND_END] = print_wall;

	/* Using the automata to print map */
	int	i = -1;
	while (info.map[++i])
	{
		a.str = info.map[i];
		a.i = 0;
		evaluate(&a);
		printf("\n");
	}
	return (0);
}
