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

void	print_empty(t_automata *a, void *data)
{
	t_data	*info;

	info = (t_data *)data;
	// Get img and put img on screen;
	printf("0");
}

void	print_wall(t_automata *a, void *data)
{
	t_data	*info;

	info = (t_data *)data;
	// Get img and put img on screen;
	printf("1");
}

void	print_exit(t_automata *a, void *data)
{
	t_data	*info;

	info = (t_data *)data;
	// Get img and put img on screen;
	printf("E");
}

void	print_collectible(t_automata *a, void *data)
{
	t_data	*info;

	info = (t_data *)data;
	// Get img and put img on screen;
	printf("C");
}
