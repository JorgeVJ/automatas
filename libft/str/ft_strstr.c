/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:58:31 by jvasquez          #+#    #+#             */
/*   Updated: 2022/05/31 20:45:25 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Find a string into another string and returns te pointer. 
*/
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	b;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		b = 0;
		while (str[i + b] && to_find[b] == str[i + b])
		{
			if (to_find[b + 1] == '\0')
				return (&str[i]);
			b++;
		}
		i++;
	}
	return (0);
}
