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
	int states[][6] = {
	//   1, P, E, C, 0, ^
		{6, 1, 1, 1, 1, 1},   // 0 Empty input
		{1, 1, 1, 1, 1, 1},   // 1 Invalid Character
		{8, 2, 3, 4, 5, 1},   // 2 Player Found
		{8, 2, 3, 4, 5, 1},   // 3 Exit Found
		{8, 2, 3, 4, 5, 1},   // 4 Collectible Found
		{8, 2, 3, 4, 5, 1},   // 5 Blank Space found
		{7, 2, 3, 4, 5, 1},   // 6 First Wall
		{8, 2, 3, 4, 5, 1},   // 7 Mid Wall
		{8, 2, 3, 4, 5, 1},   // 8 End Wall
	};

	return (states[i][j]);
}

void	automata_init(t_automata *a)
{
	alphabet_init(a);
	errors_init(a);
	sactions_init(a);
	tactions_init(a);
	a->get_state = get_state;
}

int	main(void)
{
	t_automata	a;
	t_data		info;

	ft_bzero(&a, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));
	automata_init(&a);
	a.str = ft_strdup("111CPEE1");
	printf("%s\n", a.str);
	evaluate(&a, &info);
	printf("there are:\n%d player\n%d exit\n%d collectible\n",
		info.player_count, info.exit_count, info.collect_count);
	return (0);
}