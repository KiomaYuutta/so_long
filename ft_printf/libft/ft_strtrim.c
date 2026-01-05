/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:57:05 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/08 15:28:49 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	build_string_trimed(char *rtr_start, char *rtr_end, char *rtr_str)
{
	while (rtr_start <= rtr_end)
	{
		*rtr_str = *rtr_start;
		rtr_str++;
		rtr_start++;
	}
	*rtr_str = 0;
}

static char	*check_end_string(char *s1, char *set, int count_s, int count_set)
{
	int		isfound;
	char	*rtr_p;

	count_s = ft_strlen(s1) - 1;
	rtr_p = &s1[count_s];
	while (count_s >= 0)
	{
		count_set = 0;
		isfound = 0;
		while (set[count_set] != 0)
		{
			if (s1[count_s] == set[count_set])
			{
				rtr_p = &s1[count_s - 1];
				isfound = 1;
				break ;
			}
			count_set++;
		}
		if (isfound == 0)
			break ;
		count_s--;
	}
	return (rtr_p);
}

static char	*check_start_string(char *s1, char *set, int count_s, int count_set)
{
	int		isfound;
	char	*rtr_p;

	count_s = 0;
	rtr_p = &s1[0];
	while (s1[count_s] != 0)
	{
		count_set = 0;
		isfound = 0;
		while (set[count_set] != 0)
		{
			if (s1[count_s] == set[count_set])
			{
				rtr_p = &s1[count_s + 1];
				isfound = 1;
				break ;
			}
			count_set++;
		}
		if (isfound == 0)
			break ;
		count_s++;
	}
	return (rtr_p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtr_start;
	char	*rtr_end;
	char	*rtr_str;

	if (s1 == 0 || set == 0)
		return (NULL);
	rtr_start = check_start_string((char *)s1, (char *)set, 0, 0);
	rtr_end = check_end_string((char *)s1, (char *)set, 0, 0);
	if (rtr_start > rtr_end)
	{
		rtr_str = malloc(1);
		rtr_str[0] = 0;
		return (rtr_str);
	}
	rtr_str = malloc(sizeof(char) * ((rtr_end - rtr_start) + 2));
	if (rtr_str == 0)
		return (NULL);
	build_string_trimed(rtr_start, rtr_end, rtr_str);
	return (rtr_str);
}

/* #include <stdio.h>

int	main(void)
{
	//char	*str = "  \t \t \n   \n\n\n\t";
	//char	*set = " \n\t";

	//printf("string without trim: %s\n", str);
	//printf("characters to trim: %s\n", set);
	printf("%s\n", ft_strtrim("abcdba", "acb"));

	return (0);
} */