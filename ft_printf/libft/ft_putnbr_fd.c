/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:13:00 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/23 15:29:29 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		ln_chr;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	if (ln >= 10)
		ft_putnbr_fd(ln / 10, fd);
	ln_chr = (ln % 10) + 48;
	write(fd, &ln_chr, 1);
}

/* #include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR);
	ft_putnbr_fd(INT32_MAX, fd);
	ft_putnbr_fd(INT32_MIN, fd);
	ft_putnbr_fd(0, fd);
	close(fd);
} */