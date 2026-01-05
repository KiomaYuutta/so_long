/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:00:03 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/15 17:00:03 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef short int	t_boolean;

int				ft_printf(const char *str, ...);
void			write_c(char c, int *chr_c);
void			write_str(char *s, int *chr_c);
void			write_nbr(int n, int *chr_c);
void			write_p(uintptr_t p, int *chr_c);
void			write_uint(unsigned int n, int *chr_c);
void			write_hex(unsigned int n, char c, int *chr_c);
t_boolean		is_pf_arg(char c);

#endif