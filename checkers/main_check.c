/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:07:05 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/18 11:01:10 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_main_check(int argc, char *argv[], t_map_man *map_man)
{
	if (ft_check_args(argc) == 0)
		return (0);
	if (ft_check_mapextension(argv[1]) == 0)
		return (0);
	if (ft_check_mapexist(argv[1], map_man) == 0)
		return (0);
	if (ft_check_mapshape(map_man) == 0)
		return (0);
	if (ft_checkwalls(map_man) == 0)
		return (0);
	if (ft_check_tiles(map_man) == 0)
		return (0);
	if (ft_check_entities(map_man) == 0)
		return (0);
	if (ft_checksolvable(map_man) == 0)
		return (0);
	return (1);
}
