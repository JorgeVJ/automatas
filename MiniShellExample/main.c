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

int main() {
	t_automata  a;
	t_data		info;

	ft_bzero(&a, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));

	alphabet_init(&a);
	errors_init(&a);
	sactions_init(&a);
	tactions_init(&a);
	a.str = ft_strdup(" hola|| algo< tolen>pra << TOK >> TAA && KAKA");
	printf("%s\n", a.str);

	int final = evaluate(&a, &info);
	if (final > a.errorlen)
		get_token(&a, &info);
	printf("%d\n", final);

	ft_sarrprint(info.tokens);
	return (0);
}