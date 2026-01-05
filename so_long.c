/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:04:27 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/20 19:30:40 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map_man	map_man;
	t_game_man	game_manager;

	map_man.n_collectibles = 0;
	map_man.n_collectibles_access = 0;
	map_man.map = NULL;
	if (ft_main_check(argc, argv, &map_man) == 0)
	{
		if (map_man.map != NULL)
			free_array(map_man.map, map_man.y_size);
		return (0);
	}
	free_array(map_man.map, map_man.y_size);
	set_game(&game_manager, &map_man);
	game_man(&game_manager);
	return (1);
}
