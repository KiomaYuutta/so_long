/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:10:02 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/19 17:10:02 by dide-alm         ###   ########.fr       */
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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	counter_s;
	size_t	counter_d;
	size_t	des_org_len;

	counter_s = 0;
	counter_d = ft_strlen2(dest);
	des_org_len = counter_d;
	if (size <= ft_strlen2(dest))
		return (size + ft_strlen2(src));
	while (src[counter_s] != 0 && counter_d + 1 < size)
	{
		dest[counter_d] = src[counter_s];
		counter_s++;
		counter_d++;
	}
	dest[counter_d] = 0;
	return (des_org_len + ft_strlen2(src));
}

/* #include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
	size_t r1 = strlcat(buff1, str, max);
	size_t r2 = ft_strlcat(buff2, str, max);

	printf("buff1: %s\n", buff1);
	printf("buff2: %s\n", buff2);
	printf("r1: %ld\n", r1);
	printf("r2: %ld\n", r2);

	if (r1 != r2)
		printf("Test Failed1\n");
	char s1[4] = "";
	char s2[4] = "";
	r1 = strlcat(s1, "thx to ntoniolo for this test !", 4);
	r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("r1: %ld\n", r1);
	printf("r2: %ld\n", r2);

	if (r1 != r2)
		printf("Test Failed2\n");
	printf("Test Success\n");
} */