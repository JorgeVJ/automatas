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

#include "example.h"

/* ************************************************************************** */
/*    This file will contain all the custom actions refered to the project    */
/* ************************************************************************** */

void	count_player(t_automata *a, void *data)
{
	t_data	*info;

	info = (t_data *)data;
	info->player_count++;
}

void	count_exit(t_automata *a, void *data)
{
	t_data	*info;

	info = (t_data *)data;
	info->exit_count++;
}

void	count_collectible(t_automata *a, void *data)
{
	t_data	*info;

	info = (t_data *)data;
	info->collect_count++;
}