/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:37:38 by chansjeo          #+#    #+#             */
/*   Updated: 2023/10/30 18:02:34 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8 
# elif BUFFER_SIZE <= 0
#  error "buffer size must be at least 1"
# endif

typedef struct node_s
{
	int				fd;
	char			*backup;
	struct node_s	*next;
} node_t;
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*gets_line(int fd, node_t *node, node_t *tmp);
char	*rest_buf(char *line);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_free(char *remove);

#endif
