/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:25:26 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/18 21:25:26 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	counter;
	char	*rtr_p;

	counter = 0;
	if (nmemb < 1 || size < 1)
	{
		rtr_p = malloc(1);
		return (rtr_p);
	}
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	rtr_p = malloc(nmemb * size);
	if (rtr_p == NULL)
		return (NULL);
	while (counter < nmemb * size)
	{
		rtr_p[counter] = 0;
		counter++;
	}
	return ((void *)rtr_p);
}

/* #include <stdio.h>

int	main(void)
{
	//printf("%p\n", calloc(4, 5));
	printf("%p\n", ft_calloc(0, 2));
} */