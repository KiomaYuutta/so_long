/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:46:57 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/08 11:26:27 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*s_p;
	size_t			counter;
	unsigned char	c1;
	unsigned char	c2;

	counter = 0;
	s_p = s;
	while (counter < n)
	{
		c1 = (unsigned char)s_p[counter];
		c2 = c;
		if (c1 == c2)
			return ((void *)&s_p[counter]);
		counter++;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	char	str1[] = "ola teste";

	printf("%p\n", ft_memchr(str1, 108, 4));
	printf("%p\n", ft_memchr(str1, 108, 1));
	printf("%p\n", ft_memchr(str1, 116, 7));
} */