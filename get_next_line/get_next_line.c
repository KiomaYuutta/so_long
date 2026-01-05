/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:36:22 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/23 10:36:22 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	ssize_t		n;
	char		*str_r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (*str != 0)
	{
		str_r = gnl_strjoin(fd, str);
	}
	else
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n <= 0)
			return (NULL);
		str_r = gnl_strjoin(fd, str);
	}
	return (str_r);
}
/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = 0;
	int	counter = 0;
	int	limit = 81;
	char	*str;

	//fd = open("lyrics.txt", O_RDONLY);
	//fd = open("test.txt", O_RDONLY);
	
	while (counter != limit)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		counter++;
	}
	close(fd);
} */