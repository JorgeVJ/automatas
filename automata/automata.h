/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:35:05 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 21:53:48 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_automata
{
	void	*data;
	char	**alphabet;
	char	**errors;
	char	*str;
	int		state;					// Current State
	int		ostate;					// Old/Previous State
	int		errorlen;
	int		i;
	int		j;
	void	(*fsa[20])(struct s_automata *a, void *data);
	void	(*fta[20][20])(struct s_automata *a, void *data);
	int		(*get_state)(int state, int abc_idx);
}	t_automata;

int		evaluate(t_automata *a);
void	evaluate_file(t_automata *a, char *dir, void (*f)(t_automata *a, int state));
