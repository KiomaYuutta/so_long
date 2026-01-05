/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:23:12 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/18 23:23:12 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

static size_t	ft_strlen2(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != 0)
		counter++;
	return (counter);
}

char	*ft_strdup(const char *s)
{
	size_t	counter;
	char	*str_dup;

	counter = 0;
	if (s[0] == 0)
	{
		str_dup = malloc(1);
		str_dup[0] = 0;
		return (str_dup);
	}
	str_dup = malloc(sizeof(char) * ft_strlen2(s) + 1);
	if (str_dup == 0)
		return (NULL);
	while (s[counter] != 0)
	{
		str_dup[counter] = s[counter];
		counter++;
	}
	str_dup[counter] = 0;
	return (str_dup);
}

/* #include <stdio.h>

int	main(void)
{
	char	str1[] = "";

	printf("%s\n", ft_strdup(str1));
} */