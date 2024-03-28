/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:19:42 by jvasquez          #+#    #+#             */
/*   Updated: 2023/10/04 22:19:44 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Find old string into str string and replace the old match for the new one.
*/
char	*ft_strrep(char *str, char *old, char *new)
{
	char	*found;
	char	*first;
	char	*last;

	if (!str || !old || !new || !ft_strstr(str, old))
		return (ft_strdup(str));
	found = ft_strstr(str, old);
	first = ft_substr(str, 0, found - str);
	last = ft_substr(str, found - str + ft_strlen(old),
			ft_strlen(found) - ft_strlen(old));
	return (ft_strjoinfree(first, ft_strjoinfree(new, last, 1), 2));
}
