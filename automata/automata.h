/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:35:05 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/26 16:35:08 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_automata
{
	char	**alphabet;
	char    **errors;
	char	*str;
	int     state;
	int     ostate;
	int     errorlen;
	int		i;
	int		j;
	void	(*fsa[17])(struct s_automata *a, void *data);
	void	(*fta[17][17])(struct s_automata *a, void *data);
	int		(*get_state)(int state, int abc_idx);
}	t_automata;
