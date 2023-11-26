/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:48:08 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/26 16:48:10 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

/* ************************************************************************** */
/*    This file will contain all the custom actions refered to the project    */
/* ************************************************************************** */

void get_token(t_automata *a, void *data)
{
	char	*cmdline;
	t_data	*info;

	info = (t_data *)data;
	cmdline = ft_substr(a->str, a->j, a->i - a->j);
	a->j = a->i;
	info->tokens = ft_sarradd(info->tokens, cmdline);
	free (cmdline);
}
