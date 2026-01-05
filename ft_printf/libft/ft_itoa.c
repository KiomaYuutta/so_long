/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:47:35 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/05 14:14:31 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_int_lenght(int n)
{
	long int	ln;
	size_t		len;

	ln = n;
	len = 0;
	if (ln < 0)
	{
		len++;
		ln *= -1;
	}
	while (ln >= 10)
	{
		len++;
		ln /= 10;
	}
	len++;
	return (len);
}

static void	add_ternull(char *str_int, size_t counter, int n)
{
	if (str_int[0] == '-')
		str_int[counter + ft_get_int_lenght(n) - 1] = 0;
	else
		str_int[counter + ft_get_int_lenght(n)] = 0;
}

char	*ft_itoa(int n)
{
	size_t		counter;
	long int	ln;
	char		*str_int;

	counter = ft_get_int_lenght(n) - 1;
	ln = n;
	str_int = malloc(sizeof(char) * ft_get_int_lenght(n) + 1);
	if (str_int == 0)
		return (NULL);
	if (ln < 0)
	{
		str_int[0] = 45;
		ln *= -1;
	}
	while (ln >= 10)
	{
		str_int[counter] = (ln % 10) + 48;
		ln /= 10;
		counter--;
	}
	str_int[counter] = ln + 48;
	add_ternull(str_int, counter, n);
	return (str_int);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(INT32_MAX));
	printf("%s\n", ft_itoa(INT32_MIN));
	printf("%s\n", ft_itoa(-9));
	printf("%s\n", ft_itoa(-10));
	printf("%s\n", ft_itoa(-9874));
	printf("%s\n", ft_itoa(3));
} */