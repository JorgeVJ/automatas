/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:08:26 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/29 05:16:55 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../automata/automata.h"

/* Token Types */
typedef enum e_toktype
{
	TOK_CMD,
	TOK_OPR
}	t_toktype;

typedef struct s_token
{
	t_toktype	type;
	char		*line;
	char		*cmd;
	char		**args;
	char		*infile;
	char		*outfile;
}	t_token;

typedef struct s_data
{
	t_tree		*tree;
	t_automata	*organizer; // Pointer to organizer to simplify recoursive calls
	t_token		*ctoken;	// Pointer to current organizing token to simplify recoursive calls
	int			memory;		// 32 bits to save some information for the automata
}	t_data;

/* States for tokenizer automata */
typedef enum e_tstates
{
	TA_EMPTY,
	TA_DQUOTES,
	TA_SQUOTES,
	TA_PIPE,
	TA_INVALID,
	TA_SPACES_NW,
	TA_SPACES_BTW,
	TA_NOT_OPERATOR
}	t_tstates;

/* States for organizer automata */
typedef enum e_ostates
{
	OA_EMPTY,
	OA_DQUOTES,
	OA_SQUOTES,
	OA_INVALID,
	OA_SPACES_NW,
	OA_SPACES_BTW,
	OA_LOWER,
	OA_HEREDOC,
	OA_GREATER,
	OA_APPEND,
	OA_NOT_OPERATOR,
}	t_ostates;

/* States for organizer automata */
typedef enum e_memorybits
{
	CMD_TAKEN,
	REDIR_TAKEN,
	MEM_LOWER,
	MEM_HEREDOC,
	MEM_GREATER,
	MEM_APPEND,
}	t_memorybits;

/* Tree functions */
void	printtree(void *data);
void	set_token_type(void *data);

/* ------ TOKENIZER FUNCTIONS ------ */
/* Initialization */
void	tokenizer_automata_init(t_automata *a, void *data);
void	tokenizer_alphabet_init(t_automata *a);
void	tokenizer_errors_init(t_automata *a);

/* Single Actions */
void	tokenizer_sactions_init(t_automata *a);
void	tokenizer_print_error(t_automata *a, void *data);

/* Transition Actions */
void	tokenizer_tactions_init(t_automata *a);
void	get_token(t_automata *a, void *data);

int		tokenizer_get_state(int i, int j);


/* ------ ORGANIZER FUNCTIONS ------ */
void	organizer_automata_init(t_automata *a, void *data);
void	organizer_alphabet_init(t_automata *a);
void	organizer_errors_init(t_automata *a);

/* Single Actions */
void	organizer_sactions_init(t_automata *a);
void	organizer_print_error(t_automata *a, void *data);
void	save_in_memory(t_automata *a, void *data);

/* Transition Actions */
void	organizer_tactions_init(t_automata *a);
void	organize_token(t_automata *a, void *data);
void	skip_op(t_automata *a, void *data);

int		organizer_get_state(int i, int j);
