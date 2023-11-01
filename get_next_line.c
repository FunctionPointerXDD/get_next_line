/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:00:16 by chansjeo          #+#    #+#             */
/*   Updated: 2023/11/01 11:00:02 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*rest_buf(char *line)
{
	char	*rest;
	char	*index;

	rest = 0;
	index = ft_strchr(line, '\n');
	if (index == 0)
		return (0);
	if (*(index + 1) != '\0')
	{
		rest = ft_strdup(index + 1);
		if (!rest)
			return (0);
	}
	++index;
	*index = '\0';
	return (rest);
}

char	*ft_free(char *remove)
{
	free(remove);
	return (0);
}

char	*gets_line(int fd, char *backup)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	ssize_t	nbyte;

	while (1)
	{
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte < 0)
			return (ft_free(backup));
		if (nbyte == 0)
			break ;
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		if (!backup)
			return (ft_free(tmp));
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*res;

	line = 0;
	line = gets_line(fd, backup);
	if (!line)
	{
		backup = 0;
		return (0);
	}
	backup = rest_buf(line);
	res = ft_strdup(line);
	if (!res)
	{
		free(backup);
		free(line);
		backup = 0;
		return (0);
	}
	free(line);
	return (res);
}
