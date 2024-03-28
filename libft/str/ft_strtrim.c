/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:26:42 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/21 21:55:54 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	len;
	int		p_ini;
	int		p_fin;
	char	*trim;

	if (!str)
		return (0);
	trim = "";
	len = ft_strlen(str);
	p_ini = 0;
	while (ft_strchr(set, str[p_ini]) && str[p_ini])
		p_ini++;
	p_fin = len - 1;
	while (ft_strchr(set, str[p_fin]) && p_fin > 0)
		p_fin--;
	if (p_fin < 0 || p_ini > p_fin)
		trim = ft_strdup("");
	else
		trim = ft_substr(str, p_ini, p_fin - p_ini + 1);
	return (trim);
}
