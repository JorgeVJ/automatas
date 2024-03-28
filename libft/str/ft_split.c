/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:43:26 by jvasquez          #+#    #+#             */
/*   Updated: 2022/11/17 00:38:26 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ini_move(const char *str, char delimiter, unsigned int *ini)
{
	if (*ini > ft_strlen(str))
		*ini = ft_strlen(str);
	while (str[*ini] == delimiter)
		*ini += 1;
	return (*ini);
}

static int	w_count(char **split, const char *str, char delimiter)
{
	size_t			pos;
	unsigned int	ini;
	size_t			c_word;

	ini = 0;
	ini = ini_move(str, delimiter, &ini);
	pos = ini;
	c_word = 0;
	while (str[pos])
	{
		if (str[pos + 1] == delimiter || str[pos + 1] == '\0')
		{
			if (str[ini] != delimiter && str[ini] != '\0')
			{
				if (split && ft_strlen(str) == 0)
					split[c_word] = NULL;
				else if (split)
					split[c_word] = ft_substr(str, ini, pos - ini + 1);
				c_word++;
			}
			ini = pos + 2;
		}
		pos++;
	}
	return (c_word);
}

char	**ft_split(const char *str, char delimiter)
{
	size_t	c_word;
	char	**split;

	if (!str)
		return (NULL);
	split = NULL;
	c_word = w_count(split, str, delimiter);
	split = ft_calloc(1, sizeof(char *) * (c_word + 1));
	if (!split)
		return (NULL);
	w_count(split, str, delimiter);
	return (split);
}
