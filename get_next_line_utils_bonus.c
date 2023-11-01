/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:38:01 by chansjeo          #+#    #+#             */
/*   Updated: 2023/10/31 19:35:29 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ub;
	unsigned char	uc;

	ub = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len--)
		*ub++ = uc;
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*us;

	if (s == 0)
		return (0);
	us = (const unsigned char *)s;
	while (*us != (unsigned char)c)
	{
		if (*us == '\0')
			return (0);
		us++;
	}
	return ((char *)us);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;
	char	*cp_res;

	if (s1 == 0)
		return (0);
	len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	else
	{
		cp_res = res;
		while (*s1)
			*cp_res++ = *s1++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*cp_res;
	int		len1;
	int		len2;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == 0)
		return (0);
	cp_res = res;
	while (*s1)
		*cp_res++ = *s1++;
	while (*s2)
		*cp_res++ = *s2++;
	res[len1 + len2] = '\0';
	return (res);
}
