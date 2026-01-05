/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:14:59 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/11 16:14:59 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		counter;
	char		*s_pointer;

	counter = 0;
	s_pointer = s;
	while (counter < n)
	{
		s_pointer[counter] = c;
		counter++;
	}
	return (s);
}

/* #include <stdio.h>

int	main(void)
{
	void	*str1 = malloc(100);

	ft_memset(str1, 63, 10);
	printf("%s\n", (char *)str1);
} */