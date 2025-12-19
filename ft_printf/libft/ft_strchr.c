/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:00:05 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/14 19:00:05 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			counter;
	unsigned char	c1;
	unsigned char	c2;

	counter = 0;
	c2 = c;
	while (s[counter] != 0)
	{
		c1 = (unsigned char)s[counter];
		if (c1 == c2)
			return ((char *)&s[counter]);
		counter++;
	}
	if (c2 == '\0')
		return ((char *)s + counter);
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";

	printf("%p\n", strchr(str, '\0'));
	printf("%p\n", ft_strchr(str, '\0'));
} */