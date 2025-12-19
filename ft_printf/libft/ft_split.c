/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:26:36 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/27 20:26:36 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_arr(char **str_arr, size_t counter)
{
	while (counter != 0)
	{
		free(str_arr[counter]);
		counter--;
	}
	free(str_arr[counter]);
	free(str_arr);
	return (NULL);
}

static size_t	strlen_char(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s == c)
		s++;
	while (s[counter] != c && s[counter] != 0)
		counter++;
	return (counter);
}

static size_t	str_ammount(char const *s, char c)
{
	size_t	ammount;
	int		isword;

	ammount = 0;
	isword = 0;
	while (*s != 0)
	{
		if (*s != c && isword == 0)
		{
			ammount++;
			isword = 1;
		}
		else if (*s == c)
			isword = 0;
		s++;
	}
	return (ammount);
}

static char	**build_str(char **str_arr, char const *s, size_t ct, char c)
{
	size_t	counter2;

	while (*s != 0)
	{
		if (*s != c)
		{
			str_arr[ct] = (char *)malloc(sizeof(char) * strlen_char(s, c) + 1);
			if (str_arr[ct] == NULL)
				str_arr = free_arr(str_arr, ct);
			counter2 = 0;
			while (*s != c && *s != 0)
			{
				str_arr[ct][counter2++] = *s;
				s++;
			}
			str_arr[ct][counter2] = 0;
			ct++;
			if (*s == 0)
				break ;
		}
		s++;
	}
	str_arr[ct] = 0;
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;

	if (s[0] == 0)
	{
		str_arr = malloc(sizeof(char *) * 1);
		str_arr[0] = 0;
		return (str_arr);
	}
	str_arr = (char **)malloc(sizeof(char *) * (str_ammount(s, c) + 1));
	if (str_arr == NULL)
		return (NULL);
	if (build_str(str_arr, s, 0, c) == NULL)
		return (NULL);
	return (str_arr);
}

/* #include <stdio.h>

int	main(void)
{
	char	**str_arr;
	int	counter;
	str_arr = ft_split("hello!", ' ');
	counter = 0;
	while (counter < 2)
	{
		printf("%s\n", str_arr[counter]);
		counter++;
	}
	str_arr = ft_split("hello!zzzzzzzz", 'z');
	counter = 0;
	while (counter < 2)
	{
		printf("%s\n", str_arr[counter]);
		counter++;
	}
	str_arr = ft_split("xxxxxxxxhello!", 'x');
	counter = 0;
	while (counter < 2)
	{
		printf("%s\n", str_arr[counter]);
		counter++;
	}
	str_arr = ft_split("\t\t\t\thello!\t\t\t\t", '\t');
	counter = 0;
	while (counter < 2)
	{
		printf("%s\n", str_arr[counter]);
		counter++;
	}
	str_arr = ft_split("lorem ipsum dolor sit amet,", ' ');
	counter = 0;
	while (counter < 6)
	{
		printf("%s\n", str_arr[counter]);
		counter++;
	}
	str_arr = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	counter = 0;
	while (counter < 5)
	{
		printf("%s\n", str_arr[counter]);
		counter++;
	}
	str_arr = ft_split("ggggggggggg", 'g');
	counter = 0;
	while (counter < 1)
	{
		printf("%s\n", str_arr[counter]);
		counter++;
	}
	str_arr = ft_split("nonempty", '\0');
	counter = 0;
	while (counter < 1)
	{
		printf("%s\n", str_arr[counter]);
		counter++;
	}
} */