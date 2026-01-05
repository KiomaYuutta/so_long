/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:54:41 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/08 13:24:33 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

static size_t	ft_strlen2(char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != 0)
	{
		counter++;
	}
	return (counter);
}

char	*ft_strnstr(const char *big, const char *litle, size_t len)
{
	size_t	b_counter;
	size_t	l_counter;

	b_counter = 0;
	if (*litle == 0)
		return ((char *)big);
	while (b_counter < len)
	{
		l_counter = 0;
		while (litle[l_counter] != 0 && b_counter + l_counter < len)
		{
			if (big[b_counter + l_counter] != litle[l_counter])
				break ;
			l_counter++;
		}
		if (l_counter == ft_strlen2((char *)litle))
			return ((char *)big + b_counter);
		if (big[b_counter] == 0)
			break ;
		b_counter++;
	}
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	char	big[] = "aaabcabcd";
	char	litle[] = "aabc";
	char * empty = (char*)"";
	
	printf("%s\n", ft_strnstr(big, litle, 0));
	printf("%s\n", ft_strnstr(big, litle, -1));
	printf("%s\n", ft_strnstr(big, "a", -1));
	printf("%s\n", ft_strnstr(big, "c", -1));
	printf("%s\n", ft_strnstr(empty, "", -1));
	printf("%s\n", ft_strnstr(empty, "", 0));
	printf("%s\n", ft_strnstr(empty, "coucou", -1));
	printf("%s\n", ft_strnstr(big, "aaabc",5));
	printf("%s\n", ft_strnstr(empty, "12345", 5));
	printf("%s\n", ft_strnstr(big, "abcd",9));
	printf("%s\n", ft_strnstr(big, "cd",8));
	printf("%s\n", ft_strnstr(big, "a",1));
	printf("%s\n", ft_strnstr("1", "a",1));
	printf("%s\n", ft_strnstr("22", "b",2));
} */