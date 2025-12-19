/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:08:11 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/23 15:20:52 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != 0)
	{
		write(fd, &s[counter], 1);
		counter++;
	}
	write(fd, "\n", 1);
}

/* #include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR);
	ft_putendl_fd("ola teste,", fd);
	ft_putendl_fd("string na segunda linha", fd);
	close(fd);
} */