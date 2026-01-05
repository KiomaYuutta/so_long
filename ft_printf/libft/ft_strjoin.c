/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:21:21 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/21 17:21:21 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Has NULL string check

#include "libft.h"

static void	build_str(char const *s1, char const *s2, char *joint_str)
{
	size_t	counter;
	size_t	s2_counter;

	counter = 0;
	s2_counter = 0;
	while (s1[counter] != 0)
	{
		joint_str[counter] = s1[counter];
		counter++;
	}
	while (s2[s2_counter] != 0)
	{
		joint_str[counter] = s2[s2_counter];
		counter++;
		s2_counter++;
	}
	joint_str[counter] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint_str;

	if (s1[0] == 0 && s2[0] == 0)
	{
		joint_str = malloc(1);
		joint_str[0] = 0;
		return (joint_str);
	}
	joint_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joint_str == NULL)
		return (NULL);
	build_str(s1, s2, joint_str);
	return (joint_str);
}

/* #include <stdio.h>

int	main(void)
{
	char	str1[] = "ola ";
	char	str2[] = "teste";

	printf("%s\n", ft_strjoin(str1, str2));
} */