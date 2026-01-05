/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:37:53 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/22 12:35:49 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_tiles(t_map_man *map_man)
{
	size_t	cnt_x;
	size_t	cnt_y;

	cnt_y = 0;
	while (cnt_y < map_man->y_size)
	{
		cnt_x = 0;
		while (cnt_x < map_man->x_size)
		{
			if (map_man->map[cnt_y][cnt_x] != '1'
				&& map_man->map[cnt_y][cnt_x] != '0'
				&& map_man->map[cnt_y][cnt_x] != 'C'
				&& map_man->map[cnt_y][cnt_x] != 'E'
				&& map_man->map[cnt_y][cnt_x] != 'P')
			{
				ft_printf("Error\nInvalid characters in map\n");
				return (0);
			}
			cnt_x++;
		}
		cnt_y++;
	}
	return (1);
}

int	ft_check_entities(t_map_man *map_man)
{
	char	entity;

	entity = 'C';
	while (entity != 0)
	{
		if (ft_help_checkentities(map_man, entity) == 0)
		{
			if (entity == 'C')
				ft_printf("Error\nNo collectibles\n");
			else if (entity == 'E')
				ft_printf("Error\nNumber of exits is not 1\n");
			else if (entity == 'P')
				ft_printf("Error\nNumber of players is not 1\n");
			return (0);
		}
		if (entity == 'C')
			entity = 'E';
		else if (entity == 'E')
			entity = 'P';
		else if (entity == 'P')
			entity = 0;
	}
	ft_getplayerstartposition(map_man);
	return (1);
}

int	ft_checksolvable(t_map_man *map_man)
{
	ft_flood_fill(map_man->map, map_man->p_y, map_man->p_x, map_man);
	if (map_man->exit_access != 1)
	{
		ft_printf("Error\nExit not accessible\n");
		return (0);
	}
	if (map_man->n_collectibles_access != map_man->n_collectibles)
	{
		ft_printf("Error\nNot all collectibles have access\n");
		ft_printf("Collectibles: %d / Found: %d\n",
			map_man->n_collectibles, map_man->n_collectibles_access);
		return (0);
	}
	return (1);
}
