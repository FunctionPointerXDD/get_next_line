/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:37:47 by chansjeo          #+#    #+#             */
/*   Updated: 2023/10/31 20:05:01 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_delete(node_t *remove)
{
	free(remove->backup);
	free(remove);
	return (0);
}

char	*gets_line(int fd, node_t *node)
{
	char	buf[BUFFER_SIZE + 1];
	node_t	*tmp;
	ssize_t	nbyte;

	while (1)
	{
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte < 0)
			return (ft_delete(node));
		if (nbyte == 0)
			break ;
		if (node->backup == 0)
			node->backup = ft_strdup("");
		tmp->backup = node->backup;
		node->backup = ft_strjoin(node->backup, buf);
		if (!node->backup)
			return (ft_delete(node));
		free(tmp->backup);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (node->backup);
}

node_t	*find_node(int fd, node_t **head)
{
	node_t	*node;

	node = *head;
	if (node)
	{
		while (node != 0 && node->fd == fd)
			if (node->fd == fd)
				return (node);
			node = node->next;
	}
	else
	{
		node = (node_t *)malloc(sizeof(node_t));
		if (!node)
			return (0);
		node->fd = fd;
		return (node);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static node_t	*head;
	node_t			*node;
	char			*line;
	char			*res;

	line = 0;
	head = 0;
	node = find_node(fd, &head);
	if (!node)
		return (0);
	line = gets_line(fd, node, tmp);
	if (!line)
	{
		node->backup = 0;
		return (0);
	}
	node->backup = rest_buf(line);
	res = ft_strdup(line);
	if (!res)
	{
		free(node->backup);
		free(line);
		node->backup = 0;
		return (0);
	}
	free(line);
	return (res);
}
