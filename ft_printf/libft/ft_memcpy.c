/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:06:01 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/12 11:06:01 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		counter;
	char		*dest_p;
	const char	*src_p;

	counter = 0;
	dest_p = dest;
	src_p = src;
	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest_p[0] == 0)
		dest_p[1] = 0;
	while (counter < n)
	{
		(dest_p[counter]) = src_p[counter];
		counter++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest[100];
	memset(dest, 'A', 100);
	ft_memcpy(dest, "coucou", 0);
	//1
	if (dest[0] == 'A')
		printf ("Success1\n");
	char *rtn = (char *)ft_memcpy(dest, NULL, 0);
	//2  
	if (rtn == dest && dest[0] == 'A')
		printf ("Success2\n");
	char src[] = {0, 0};
	ft_memcpy(dest, src, 2);
	int i = 2;
	//3 
	if (i == 2 && dest[2] == 'A')
			printf ("Success3\n");
	write(1, "\n", 1);
	return (0);
} */