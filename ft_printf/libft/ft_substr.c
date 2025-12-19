/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:18:04 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/21 16:18:04 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

static size_t	ft_strlen2(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != 0)
		counter++;
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	counter;
	char	*substr;

	counter = 0;
	if (s[0] == 0 || start >= ft_strlen2(s))
	{
		substr = malloc(1);
		substr[0] = 0;
		return (substr);
	}
	if (len <= ft_strlen2(s + start))
		substr = (char *)malloc(sizeof(char) * len + 1);
	else
		substr = (char *)malloc(sizeof(char) * ft_strlen2(s + start) + 1);
	if (substr == NULL)
		return (NULL);
	len = len + start;
	while (start < len && s[start] != 0)
	{
		substr[counter] = s[start];
		start++;
		counter++;
	}
	substr[counter] = 0;
	return (substr);
}

/* #include <stdio.h>

int	main(void)
{
	//char	str1[] = "";

	printf("%s\n", ft_substr("i just want this part #############", 0, 22));
} */