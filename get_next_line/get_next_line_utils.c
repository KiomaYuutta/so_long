/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:36:23 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/23 10:36:23 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	gnl_strlen(char *str)
{
	ssize_t	counter;

	counter = 0;
	if (str == 0)
		return (0);
	if (*str == '\n')
		return (1);
	while ((unsigned int)*str != '\n' && (unsigned int)*str != '\0')
	{
		counter++;
		str++;
	}
	if ((unsigned int)*str == '\n')
		counter++;
	return (counter);
}

void	gnl_memmove(char *str_s)
{
	ssize_t		counter;
	char		*str_e;

	if (*str_s == 0)
		return ;
	counter = 0;
	str_e = gnl_strchr(str_s, '\n');
	if (str_e != NULL)
	{
		str_e++;
		while (*str_e != 0)
		{
			*str_s = *str_e;
			counter++;
			str_s++;
			str_e++;
		}
	}
	while (counter != BUFFER_SIZE)
	{
		*str_s = 0;
		str_s++;
		counter++;
	}
}

char	*gnl_bldstr(char *str_i, char *str_s)
{
	char	*str_r;
	ssize_t	cnt_r;
	ssize_t	cnt;

	cnt_r = 0;
	cnt = 0;
	str_r = malloc(1 * (gnl_strlen(str_i) + gnl_strlen(str_s) + 1));
	if (str_r == NULL)
		return (NULL);
	if (str_i != NULL)
	{
		while (str_i[cnt] != 0)
			str_r[cnt_r++] = str_i[cnt++];
		free (str_i);
	}
	cnt = 0;
	while (str_s[cnt] != '\n' && str_s[cnt] != '\0')
		str_r[cnt_r++] = str_s[cnt++];
	if (str_s[cnt] == '\n')
		str_r[cnt_r++] = '\n';
	str_r[cnt_r] = 0;
	return (str_r);
}

char	*gnl_strchr(char *str, unsigned int c)
{
	while (*str != 0)
	{
		if ((unsigned int)*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (0);
}

char	*gnl_strjoin(int fd, char *str)
{
	char	*str_r;
	ssize_t	n;

	str_r = NULL;
	while (gnl_strchr(str, '\n') == 0)
	{
		str_r = gnl_bldstr(str_r, str);
		n = read(fd, str, BUFFER_SIZE);
		if (str_r == NULL || n <= 0)
		{
			gnl_memmove(str);
			if (n == 0)
				return (str_r);
			else if (n < 0)
				free(str_r);
			return (NULL);
		}
		else if (n < BUFFER_SIZE)
			gnl_memmove(str + n);
	}
	str_r = gnl_bldstr(str_r, str);
	gnl_memmove(str);
	return (str_r);
}
