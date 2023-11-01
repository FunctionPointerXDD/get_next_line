/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:57:48 by chansjeo          #+#    #+#             */
/*   Updated: 2023/11/01 10:48:22 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void check()
{
	system("leaks a.out");
}

int main()
{
	int i;
	char *tmp;
	int idx = 1;
	i = open("test.txt", O_RDONLY);
//	printf("%s",get_next_line(1));
	while (1)
	{
		tmp = get_next_line(i);
		printf("%d: %s\n", idx++, tmp);
		if (!tmp)
			break;
	}

    atexit(check);
	return 0;
}
