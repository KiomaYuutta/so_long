/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:36:32 by dide-alm          #+#    #+#             */
/*   Updated: 2025/04/11 15:36:32 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* #include <stdio.h>

int     main(void)
{
        printf("%d\n", ft_isprint(68));
        printf("%d\n", ft_isprint(-60));
        printf("%d\n", ft_isprint(32));
        printf("%d\n", ft_isprint(126));
        printf("%d\n", ft_isprint(655));
} */