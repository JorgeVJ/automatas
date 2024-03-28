/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:17:45 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/16 17:16:16 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_strfree(char **buf)
{
	free (buf[0]);
	buf[0] = NULL;
	return (NULL);
}

/*int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}*/

ssize_t	ft_bufjoin(char **buf, int fd)
{
	char	*joined;
	int		i;
	int		j;
	char	*str;
	ssize_t	size;

	size = 0;
	str = ft_fillbuf(&size, fd);
	if (!str ||!size)
		return (size);
	joined = malloc(sizeof(char) * (size + ft_strlen(buf[0]) + 1));
	if (!joined)
		return (size);
	i = -1;
	while (buf[0][++i] != '\0')
		joined[i] = buf[0][i];
	j = -1;
	while (str[++j] != '\0')
		joined[i++] = str[j];
	joined[i] = '\0';
	free (str);
	str = NULL;
	free (buf[0]);
	buf[0] = joined;
	return (size);
}

void	ft_cleanbuf(char **buf)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (buf[0][i] != '\0' && buf[0][i] != '\n')
		i++;
	if (buf[0][i] == '\0')
	{
		free (buf[0]);
		buf[0] = NULL;
		return ;
	}
	str = malloc(sizeof(char) * (ft_strlen(buf[0]) - i + 1));
	if (!str)
		return ;
	j = 0;
	while (buf[0][++i] != '\0')
		str[j++] = buf[0][i];
	str[j] = '\0';
	free (buf[0]);
	*buf = str;
}

char	*ft_getline(char **buf, int fd)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (buf[0][i] != '\n' && buf[0][i] != '\0')
	{
		if (buf[0][i + 1] == '\0')
			ft_bufjoin(buf, fd);
		i++;
	}
	if (buf[0][i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = buf[0][j];
	if (buf[0][i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	ft_cleanbuf(buf);
	return (line);
}
