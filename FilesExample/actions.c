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

void	ambient(t_automata *a, void *data)
{
	printf("There's an ambient light\n");
}

void	camera(t_automata *a, void *data)
{
	printf("There's a camera\n");
}

void	light(t_automata *a, void *data)
{
	printf("There's a light\n");
}

void	sphere(t_automata *a, void *data)
{
	printf("There's a sphere\n");
}

void	plane(t_automata *a, void *data)
{
	printf("There's a plane\n");
}

void	cylinder(t_automata *a, void *data)
{
	printf("There's a cylinder\n");
}
