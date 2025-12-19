/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:22:12 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/05 18:56:46 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

/* static char	ft_toupper2(unsigned int n, char c)
{
	n--;
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	counter;
	char	*str_rst;

	counter = 0;
	if (s[0] == 0)
	{
		str_rst = malloc(1);
		str_rst[0] = 0;
		return (str_rst);
	}
	str_rst = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str_rst == 0)
		return (NULL);
	while (s[counter] != 0)
	{
		str_rst[counter] = f(counter, s[counter]);
		counter++;
	}
	str_rst[counter] = 0;
	return (str_rst);
}

/* #include <stdio.h>

int	main(void)
{
	char	str1[] = "";

	printf("%s\n", ft_strmapi(str1, ft_toupper2));
} */