/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:42:19 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/14 15:42:19 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		counter;
	char		*dest_p;
	const char	*src_p;

	counter = 0;
	dest_p = dest;
	src_p = src;
	if (n == 0)
	{
		dest_p = "";
		return (dest);
	}
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		while (n-- > counter)
			dest_p[n] = src_p[n];
	}
	else
	{
		while (counter++ < n)
			dest_p[counter - 1] = src_p[counter - 1];
	}
	return (dest);
}

/* #include <stdio.h>

int     main(void)
{
	char	str1[] = "teste";
	char	str2[] = "olara";

        printf("%s\n", str1);
        printf("%s\n", str2);
	ft_memmove((void *)0, (void *)0, 0);
	printf("%s\n", str1);
	printf("%s\n", str2);
} */