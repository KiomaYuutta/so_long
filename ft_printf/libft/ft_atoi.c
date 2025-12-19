/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:03:32 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/18 16:03:32 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	counter;
	int		is_neg;
	int		result;

	counter = 0;
	is_neg = 1;
	result = 0;
	while (nptr[counter] == 32 || (nptr[counter] >= 9 && nptr[counter] <= 13))
		counter++;
	if (nptr[counter] == 45 || nptr[counter] == 43)
	{
		if (nptr[counter] == 45)
			is_neg = -1;
		counter++;
	}
	while (nptr[counter] >= 48 && nptr[counter] <= 57)
	{
		result = result * 10 + (nptr[counter] - 48);
		counter++;
	}
	return (result * is_neg);
}

/* #include <stdio.h>

int	main(void)
{
	char	str1[] = " 	 -15632";
	char	str2[] = "-85934";
	char	str3[] = "     		+975842";

	printf("%d\n", ft_atoi(str1));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", ft_atoi(str3));
} */