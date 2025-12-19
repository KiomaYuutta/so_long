/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:57:38 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/14 19:57:38 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			counter;
	char			*last_ap;
	unsigned char	c1;
	unsigned char	c2;

	counter = 0;
	last_ap = 0;
	c2 = c;
	while (s[counter] != 0)
	{
		c1 = (unsigned char)s[counter];
		if (c1 == c2)
			last_ap = ((char *)&s[counter]);
		counter++;
	}
	if (c2 == 0)
		return ((char *)s + counter);
	return (last_ap);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%p\n", ft_strrchr("testestring", 't'));
	printf("%p\n", ft_strrchr("testestring", 'd'));
	printf("%p\n", ft_strrchr("", 't'));
	printf("%p\n", ft_strrchr("teste", '\0'));
} */