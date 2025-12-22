/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:48:30 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/10 13:48:30 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countlines(int *map_fd, size_t *x_size, char *map_name)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = get_next_line(*map_fd);
	if (str == NULL)
	{
		ft_printf("Error\nFile empty\n");
		close(*map_fd);
		return (0);
	}
	*x_size = ft_strlen(str) - 2;
	while (str != NULL)
	{
		free(str);
		cnt++;
		str = get_next_line(*map_fd);
	}
	close(*map_fd);
	*map_fd = open(map_name, O_RDONLY);
	return (cnt);
}

int	ft_setmap_check(t_map_man *map_man)
{
	size_t				cnt;

	cnt = 0;
	map_man->y_size = ft_countlines(&(map_man->map_fd),
			&map_man->x_size, map_man->map_name);
	if (map_man->y_size == 0)
		return (0);
	map_man->map = (char **)calloc(sizeof (char *), map_man->y_size + 1);
	while (cnt < map_man->y_size - 1)
	{
		map_man->map[cnt] = get_next_line(map_man->map_fd);
		cnt++;
	}
	map_man->map[cnt] = get_next_line(map_man->map_fd);
	close(map_man->map_fd);
	map_man->map_fd = open(map_man->map_name, O_RDONLY);
	return (1);
}

int	ft_setmap_game(t_game_man *game_man, t_map_man *map_man)
{
	size_t				cnt;

	cnt = 0;
	game_man->y_size = ft_countlines(&map_man->map_fd,
			(size_t *)&game_man->x_size, map_man->map_name);
	if (game_man->y_size == 0)
		return (0);
	game_man->map = (char **)calloc(sizeof (char *), game_man->y_size + 1);
	while (cnt < map_man->y_size - 1)
	{
		game_man->map[cnt] = get_next_line(map_man->map_fd);
		game_man->map[cnt][game_man->x_size] = 0;
		cnt++;
	}
	game_man->map[cnt] = get_next_line(map_man->map_fd);
	close(map_man->map_fd);
	return (1);
}
