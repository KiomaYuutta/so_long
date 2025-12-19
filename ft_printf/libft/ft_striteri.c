/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:29:58 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/05 18:53:43 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	counter;

	counter = 0;
	if (s[0] == 0)
		return ;
	while (s[counter] != 0)
	{
		f(counter, &s[counter]);
		counter++;
	}
}

/* #include <stdio.h>

int	main(void)
{
	char	str1[] = "";

	printf("%s\n", str1);
	ft_striteri(str1, ft_toupper2);
	printf("%s\n", str1);
} */