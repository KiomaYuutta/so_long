/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:05:45 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/11 19:05:45 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t		counter;
	char		*s_pointer;

	counter = 0;
	s_pointer = s;
	while (counter < n)
	{
		s_pointer[counter] = '\0';
		counter++;
	}
	return (s);
}

/* int	main(void)
{
	char	str1[] = "olateste";

	ft_bzero(str1, 10);
} */