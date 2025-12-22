/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_man_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:26:05 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/20 20:14:36 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*get_sprite(t_game_man *game_man, int x_pos, int y_pos)
{
	if (game_man->map[y_pos][x_pos] == '1')
		return (game_man->images.wall);
	else if (game_man->map[y_pos][x_pos] == '0')
		return (game_man->images.ground);
	else if (game_man->map[y_pos][x_pos] == 'P')
		return (game_man->images.player);
	else if (game_man->map[y_pos][x_pos] == 'E')
		return (game_man->images.exit_off);
	else if (game_man->map[y_pos][x_pos] == 'H')
		return (game_man->images.exit_on);
	else if (game_man->map[y_pos][x_pos] == 'C')
		return (game_man->images.collectible);
	return (NULL);
}

void	set_sprites(t_game_man *game)
{
	int	s;

	s = 64;
	game->images.collectible = mlx_xpm_file_to_image(game->mlx,
			COLLECTIBLE_IMG, &s, &s);
	game->images.exit_off = mlx_xpm_file_to_image(game->mlx,
			EXITOFF_IMG, &s, &s);
	game->images.exit_on = mlx_xpm_file_to_image(game->mlx, EXITON_IMG, &s, &s);
	game->images.player = mlx_xpm_file_to_image(game->mlx, PLAYER_IMG, &s, &s);
	game->images.wall = mlx_xpm_file_to_image(game->mlx, WALL_IMG, &s, &s);
	game->images.ground = mlx_xpm_file_to_image(game->mlx, GROUND_IMG, &s, &s);
}

void	build_sprites(t_game_man *game)
{
	int	cnt_x;
	int	cnt_y;

	cnt_y = 0;
	while (cnt_y < game->y_size)
	{
		cnt_x = 0;
		while (cnt_x < game->x_size)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				get_sprite(game, game->exit_x, game->exit_y),
				game->exit_x * 64, game->exit_y * 64);
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				get_sprite(game, cnt_x, cnt_y), cnt_x * 64, cnt_y * 64);
			cnt_x++;
		}
		cnt_y++;
	}
	put_str_window(game);
}

int	keyhook_handler(int keycode, t_game_man *game)
{
	if (keycode == ESC_KEY)
		close_game(game);
	if (keycode == W_KEY && game->map[game->cp_y - 1][game->cp_x] != '1')
		move_player(game, 'w');
	if (keycode == A_KEY && game->map[game->cp_y][game->cp_x - 1] != '1')
		move_player(game, 'a');
	if (keycode == S_KEY && game->map[game->cp_y + 1][game->cp_x] != '1')
		move_player(game, 's');
	if (keycode == D_KEY && game->map[game->cp_y][game->cp_x + 1] != '1')
		move_player(game, 'd');
	return (1);
}

void	free_array(char **map, int y_size)
{
	while (y_size > -1)
	{
		free(map[y_size]);
		y_size--;
	}
	free(map);
}
