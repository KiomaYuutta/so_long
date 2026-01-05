/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:34:28 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/15 23:34:28 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_c(char c, int *chr_c)
{
	write(1, &c, 1);
	*chr_c += 1;
}

void	write_str(char *s, int *chr_c)
{
	size_t	counter;

	counter = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*chr_c += 6;
		return ;
	}
	while (s[counter] != 0)
	{
		write(1, &s[counter], 1);
		counter++;
		*chr_c += 1;
	}
}

void	write_nbr(int n, int *chr_c)
{
	long int	ln;
	char		ln_chr;

	ln = n;
	if (ln < 0)
	{
		write(1, "-", 1);
		ln *= -1;
		*chr_c += 1;
	}
	if (ln >= 10)
		write_nbr(ln / 10, chr_c);
	ln_chr = (ln % 10) + 48;
	write(1, &ln_chr, 1);
	*chr_c += 1;
}
