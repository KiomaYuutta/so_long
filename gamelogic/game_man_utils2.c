/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_man_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:26:35 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/18 11:25:59 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect_collectibles(t_game_man *game, char move)
{
	if ((move == 'w' && game->map[game->cp_y - 1][game->cp_x] == 'C')
		|| (move == 'a' && game->map[game->cp_y][game->cp_x - 1] == 'C')
		|| (move == 's' && game->map[game->cp_y + 1][game->cp_x] == 'C')
		|| (move == 'd' && game->map[game->cp_y][game->cp_x + 1] == 'C'))
		game->current_c++;
}

void	move_player(t_game_man *game, char move)
{
	collect_collectibles(game, move);
	if (move == 'w')
		game->map[game->cp_y--][game->cp_x] = '0';
	if (move == 'a')
		game->map[game->cp_y][game->cp_x--] = '0';
	if (move == 's')
		game->map[game->cp_y++][game->cp_x] = '0';
	if (move == 'd')
		game->map[game->cp_y][game->cp_x++] = '0';
	if (game->current_c == game->max_c)
		game->map[game->exit_y][game->exit_x] = 'H';
	else
		game->map[game->exit_y][game->exit_x] = 'E';
	game->map[game->cp_y][game->cp_x] = 'P';
	ft_printf("Movements: %d\n", ++game->movements);
	if (game->cp_y == game->exit_y && game->cp_x == game->exit_x
		&& game->current_c == game->max_c)
		end_game(game);
	build_sprites(game);
}

void	put_str_window(t_game_man *game)
{
	char	*str;

	str = ft_itoa(game->movements);
	mlx_string_put(game->mlx, game->mlx_window, 32, 20, 16777215, "Movements:");
	mlx_string_put(game->mlx, game->mlx_window, 100, 20, 16777215, str);
	free (str);
}
