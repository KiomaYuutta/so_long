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

void	write_uint(unsigned int n, int *chr_c)
{
	char	c;

	if (n >= 10)
		write_uint(n / 10, chr_c);
	c = (n % 10) + 48;
	write(1, &c, 1);
	*chr_c += 1;
}

void	write_hex(unsigned int n, char c, int *chr_c)
{
	static const char	*hex_l;
	static const char	*hex_u;

	hex_l = "0123456789abcdef";
	hex_u = "0123456789ABCDEF";
	if (n >= 16)
	{
		write_hex(n / 16, c, chr_c);
	}
	if (c == 'X')
		write(1, &hex_u[n % 16], 1);
	else
		write(1, &hex_l[n % 16], 1);
	*chr_c += 1;
}

void	write_p(uintptr_t p, int *chr_c)
{
	static const char	*hex_l;

	hex_l = "0123456789abcdef";
	if (p >= 16)
	{
		write_p(p / 16, chr_c);
	}
	write(1, &hex_l[p % 16], 1);
	*chr_c += 1;
}

t_boolean	is_pf_arg(char c)
{
	char	*compare_c;

	compare_c = "cspdiuxX";
	if (c == 0)
		return (0);
	while (*compare_c != 0)
	{
		if (c == *compare_c)
			return (1);
		compare_c++;
	}
	return (0);
}
