/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:51:13 by jvasquez          #+#    #+#             */
/*   Updated: 2024/04/12 19:15:57 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

/* Function to iterate the Tree to evaluate and organize the tokens */
void	evaluate_token(void *data, void *context)
{
	int		finalstate;
	t_token	*token;
	t_data	*info;

	token = (t_token *)data;
	info = (t_data *)context;

	info->ctoken = token;				// Set the token pointer to access easily from organize_token function
	info->organizer->str = token->line;	// Set the organizer string to be analized
	info->organizer->i = 0;				// Reset the automata data
	info->organizer->j = 0;
	info->organizer->state = 0;
	info->organizer->ostate = 0;
	info->memory = 0;

	finalstate = evaluate(info->organizer);
	if (finalstate > info->organizer->errorlen)
		organize_token(info->organizer, info);
	else
		printf("%s\n", info->organizer->errors[finalstate]);
}

int	main(void)
{
	t_automata	tokenizer;
	t_automata	organizer;
	t_data		info;
	int			finalstate;

	ft_bzero(&tokenizer, sizeof(t_automata));
	ft_bzero(&organizer, sizeof(t_automata));
	ft_bzero(&info, sizeof(t_data));
	tokenizer_automata_init(&tokenizer, &info);
	organizer_automata_init(&organizer, &info);

	/* Evaluates the first automata and check if the last state is valid */
	tokenizer.str = ft_strdup(" cat -e < infile1 < infile2 > outfile1 >> outfile2 > outfile3 | cmd <> iofile | cmd2 | cmd3");
	// printf("%s\n", tokenizer.str);

	finalstate = evaluate(&tokenizer);
	if (finalstate > tokenizer.errorlen)
		get_token(&tokenizer, &info);
	else
		printf("%s\n", tokenizer.errors[finalstate]);

	// printf("\nImprimir árbol tokenizado\n");
	// tree_in_order(info.tree, printtree);


	/* Set token type to CMD or OPERATOR */
	tree_in_order(info.tree, set_token_type);


	/* Evaluates the second automata and check if the last state is valid */
	info.organizer = &organizer;
	tree_in_order_context(info.tree, evaluate_token, &info);

	printf("\nImprimir arbol organizado\n");
	tree_in_order(info.tree, printtree);
	return (0);
}