/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_mapshape_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:47:37 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/10 13:47:37 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_help_checkentities(t_map_man *map_man, char entity)
{
	size_t	cnt_x;
	size_t	cnt_y;
	int		cnt_e;

	cnt_e = 0;
	cnt_y = 0;
	while (cnt_y < map_man->y_size)
	{
		cnt_x = 0;
		while (cnt_x < map_man->x_size)
		{
			if (map_man->map[cnt_y][cnt_x] == entity)
				cnt_e++;
			if (map_man->map[cnt_y][cnt_x] == 'C' && entity == 'C')
				(map_man->n_collectibles)++;
			cnt_x++;
		}
		cnt_y++;
	}
	if ((entity == 'C' && cnt_e == 0)
		|| (entity == 'E' && cnt_e != 1)
		|| (entity == 'P' && cnt_e != 1))
		return (0);
	return (1);
}

void	ft_getplayerstartposition(t_map_man *map_man)
{
	size_t	cnt_x;
	size_t	cnt_y;

	cnt_y = 0;
	while (cnt_y < map_man->y_size)
	{
		cnt_x = 0;
		while (cnt_x < map_man->x_size)
		{
			if (map_man->map[cnt_y][cnt_x] == 'P')
			{
				map_man->p_x = cnt_x;
				map_man->p_y = cnt_y;
				return ;
			}
			cnt_x++;
		}
		cnt_y++;
	}
}

void	ft_get_exit_position(t_game_man *game)
{
	int	cnt_x;
	int	cnt_y;

	cnt_y = 0;
	while (cnt_y < game->y_size)
	{
		cnt_x = 0;
		while (cnt_x < game->x_size)
		{
			if (game->map[cnt_y][cnt_x] == 'E')
			{
				game->exit_x = cnt_x;
				game->exit_y = cnt_y;
				return ;
			}
			cnt_x++;
		}
		cnt_y++;
	}
}

void	ft_flood_fill(char **map, int p_y, int p_x, t_map_man *map_man)
{
	if (map[p_y][p_x] == 'C')
		(map_man->n_collectibles_access)++;
	if (map[p_y][p_x] != 'E')
	{
		map[p_y][p_x] = '1';
		if (map[p_y + 1][p_x] != '1')
			ft_flood_fill(map, p_y + 1, p_x, map_man);
		if (map[p_y][p_x + 1] != '1')
			ft_flood_fill(map, p_y, p_x + 1, map_man);
		if (map[p_y - 1][p_x] != '1')
			ft_flood_fill(map, p_y - 1, p_x, map_man);
		if (map[p_y][p_x - 1] != '1')
			ft_flood_fill(map, p_y, p_x - 1, map_man);
	}
	if (map[p_y][p_x] == 'E')
		map_man->exit_access = 1;
}
