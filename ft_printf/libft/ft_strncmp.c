/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:13:26 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/30 16:13:26 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			counter;

	if (n == 0)
		return (0);
	counter = 0;
	while (s1[counter] != 0 && s2[counter] != 0 && counter < n)
	{
		c1 = (unsigned char)s1[counter];
		c2 = (unsigned char)s2[counter];
		if (c1 != c2)
			break ;
		counter++;
	}
	c1 = (unsigned char)s1[counter];
	c2 = (unsigned char)s2[counter];
	if (counter == n)
		return (s1[counter - 1] - s2[counter - 1]);
	else
		return (c1 - c2);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", strncmp("Test\200", "Test\0", 6));
	printf("%d\n", ft_strncmp("Test\200", "Test\0", 6));
} */