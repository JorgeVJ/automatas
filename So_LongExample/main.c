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

int	main(void)
{
	t_automata	a;
	t_data		info;

	ft_bzero(&a, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));
	automata_init(&a, &info);
	a.str = ft_strdup("111CPEE1");
	printf("%s\n", a.str);
	evaluate(&a);
	printf("there are:\n%d player\n%d exit\n%d collectible\n",
		info.player_count, info.exit_count, info.collect_count);
	return (0);
}