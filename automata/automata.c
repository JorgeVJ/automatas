/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:53:38 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 22:20:55 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "automata.h"

int	idx(char *alphabet[], char c)
{
	int	i;

	i = -1;
	while (alphabet[++i])
		if (ft_chrpos(alphabet[i], c, 0) != -1)
			return (i);
	return (i);
}

int	evaluate(t_automata *a)
{
	a->ostate = 0;
	a->i = -1;
	while (++a->i < ft_strlen(a->str))
	{
		a->state = a->get_state(a->state, idx(a->alphabet, a->str[a->i]));
		if (a->fsa[a->state])
			a->fsa[a->state](a, a->data);
		if (a->fta[a->ostate][a->state])
			a->fta[a->ostate][a->state](a, a->data);
		a->ostate = a->state;
	}
	return (a->state);
}

void	evaluate_file(t_automata *a, char *dir,
		void (*f)(t_automata *a, int state))
{
	int		file;
	char	*line;

	file = open(dir, O_RDONLY);
	line = get_next_line(file);
	while (line)
	{
		a->str = line;
		a->state = 0;
		f(a, evaluate(a));
		free (line);
		line = get_next_line(file);
	}
	close(file);
}
