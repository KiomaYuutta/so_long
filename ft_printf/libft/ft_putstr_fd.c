/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:00:45 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/21 13:10:01 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != 0)
	{
		write(fd, &s[counter], 1);
		counter++;
	}
}

/* #include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR);
	ft_putstr_fd("", fd);
	close(fd);
} */