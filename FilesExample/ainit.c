/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ainit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:39 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/26 16:34:42 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "example.h"

/**
 * 	Alphabet definitions
**/
void	alphabet_init(t_automata *a)
{
	a->alphabet = ft_sarradd(NULL, " ");
	a->alphabet = ft_sarradd(a->alphabet, "#");
	a->alphabet = ft_sarradd(a->alphabet, "A");
	a->alphabet = ft_sarradd(a->alphabet, "C");
	a->alphabet = ft_sarradd(a->alphabet, "L");
	a->alphabet = ft_sarradd(a->alphabet, "p");
	a->alphabet = ft_sarradd(a->alphabet, "s");
	a->alphabet = ft_sarradd(a->alphabet, "c");
	a->alphabet = ft_sarradd(a->alphabet, "l");
	a->alphabet = ft_sarradd(a->alphabet, "y");
	a->alphabet = ft_sarradd(a->alphabet, "\n");
	a->alphabet = ft_sarradd(a->alphabet, "-0123456789.,\t ");
}

int	get_state(int i, int j)
{
	const int states[][12] = {
	//   \s, #, A, C, L, p, s, c, l, y,\n, V, ^
		{ 0, 2, 3, 4, 5, 9,10,11, 1, 1, 0, 1, 1},   //  0 Empty input
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},   //  1 Invalid Character
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},   //  2 Comment
		{12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},   //  3 Ambient Light
		{12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},   //  4 Camera
		{12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},   //  5 Light
		{12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},   //  6 Plane
		{12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},   //  7 Sphere
		{12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},   //  8 Cylinder
		{ 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1},   //  9 M_Plane
		{ 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1},   // 10 M_Sphere
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1},   // 11 M_Cylinder
		{12,12,12,12,12,12,12,12,12,12,12,12, 1},   // 12 Found element
	};

	return (states[i][j]);
}

/**
 * 	Error strings to print when automata finish on a
 * 		non finish state.
**/
void	errors_init(t_automata *a)
{
	a->errors = NULL;
	a->errors = ft_sarradd(NULL, " ");
	a->errors = ft_sarradd(a->errors, "Invalid character");
	a->errors = ft_sarradd(a->errors, "Comment line for tests");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errors = ft_sarradd(a->errors, "Unknown element");
	a->errorlen = ft_sarrsize(a->errors);
}

/**
 *	Simple actions, they trigger when getting a certain state. 
**/
void	sactions_init(t_automata *a)
{
}

/**
 *	Transition actions, they trigger when going
 * 		from a certain state to another.
**/
void	tactions_init(t_automata *a)
{
	a->fta[AMBIENT][FOUND_ELEM] = ambient;
	a->fta[CAMERA][FOUND_ELEM] = camera;
	a->fta[LIGHT][FOUND_ELEM] = light;
	a->fta[SPHERE][FOUND_ELEM] = sphere;
	a->fta[PLANE][FOUND_ELEM] = plane;
	a->fta[CYLINDER][FOUND_ELEM] = cylinder;
}
