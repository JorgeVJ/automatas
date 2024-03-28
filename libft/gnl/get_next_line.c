/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:29:09 by jvasquez          #+#    #+#             */
/*   Updated: 2022/07/16 17:16:15 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fillbuf(ssize_t *size, int fd)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*size = read(fd, buf, BUFFER_SIZE);
	if (!*size)
		return (ft_strfree(&buf));
	buf[*size] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*files[4096];
	ssize_t		size;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!files[fd])
	{
		files[fd] = ft_fillbuf(&size, fd);
		if (!files[fd])
			return (NULL);
	}
	if (!files[fd][0])
		if (!ft_bufjoin(&files[fd], fd))
			return (ft_strfree(&files[fd]));
	return (ft_getline(&files[fd], fd));
}
