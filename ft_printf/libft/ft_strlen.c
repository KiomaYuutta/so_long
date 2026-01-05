/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:57:41 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/11 15:57:41 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "../ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != 0)
		counter++;
	return (counter);
}

/* #include <stdio.h>

int     main(void)
{
        printf("%zu\n", ft_strlen("68"));
        printf("%zu\n", ft_strlen("fkaoep"));
        printf("%zu\n", ft_strlen("ola teste"));
        printf("%zu\n", ft_strlen("     "));
        printf("%zu\n", ft_strlen("	ofnma 	"));
	printf("%zu\n", ft_strlen(""));
} */