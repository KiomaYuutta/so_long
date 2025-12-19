/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:16:18 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/07 15:55:45 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	const char		*s1_p;
	const char		*s2_p;
	size_t			counter;

	counter = 0;
	s1_p = s1;
	s2_p = s2;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		c1 = (unsigned char)s1_p[counter];
		c2 = (unsigned char)s2_p[counter];
		if (c1 != c2)
			break ;
		counter++;
	}
	if (counter == n)
		return (s1_p[counter - 1] - s2_p[counter - 1]);
	c1 = (unsigned char)s1_p[counter];
	c2 = (unsigned char)s2_p[counter];
	return (c1 - c2);
}

/* #include <stdio.h>

int	main(void)
{
	size_t size = 8;
	int	teste;
 	char *b1 = malloc(10);
 	char *b2 = malloc(10);
 
 	b1[0] = '.'; b1[1] = '.'; b1[2] = '.'; b1[3] = '.'; b1[4] = '.';
	b1[5] = '.'; b1[6] = '.'; b1[7] = '.'; b1[8] = '.'; b1[9] = '\0';
	b2[0] = '.'; b2[1] = '.'; b2[2] = '.'; b2[3] = '.'; b2[4] = '.';
	b2[5] = '.'; b2[6] = '.'; b2[7] = '.'; b2[8] = '.'; b2[9] = '\0';
 	teste = ft_memcmp(b1, b2, size);
 	printf("Success");
} */