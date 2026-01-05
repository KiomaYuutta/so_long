/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:52:46 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/19 13:52:46 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

static	size_t	ft_strlen2(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != 0)
		counter++;
	return (counter);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;
	size_t	src_len;

	counter = 0;
	src_len = ft_strlen2(src);
	if (src[0] == 0)
	{
		dest[counter] = 0;
		return (0);
	}
	if (size == 0)
		return (src_len);
	while (src[counter] != 0 && counter < size - 1)
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = 0;
	return (src_len);
}

/* #include <bsd/string.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str = "hello !";
	char buff1[0xF00];
	char buff2[0xF00];
	size_t r1;
	size_t r2;

	memset(buff1, 'A', 20);
	memset(buff2, 'A', 20);
	r1 = strlcpy(buff1, str, 0);
	r2 = ft_strlcpy(buff2, str, 0);
	printf("%ld\n", r1);
	printf("%ld\n", r2);
	printf("strlcpy: %s\n", buff1);
	printf("ft_strlcpy: %s\n", buff2);
	printf("%d\n", memcmp(buff1, buff2, 20));
	if (r1 == r2 && !memcmp(buff1, buff2, 20))
		printf("SUCCESS");
	printf("FAILED");
	return (0);
} */