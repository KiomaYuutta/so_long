/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:36:24 by dide-alm          #+#    #+#             */
/*   Updated: 2025/05/23 10:36:24 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50 
# endif
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef short int	t_bolean;

char		*get_next_line(int fd);
void		gnl_memmove(char *str_s);
char		*gnl_strjoin(int fd, char *str);
char		*gnl_strchr(char *str, unsigned int c);
char		*gnl_bldstr(char *str_i, char *str_s);
ssize_t		gnl_strlen(char *str);

#endif