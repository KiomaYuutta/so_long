/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:24:03 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:24:03 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_game(t_game_man *game_man)
{
	mlx_destroy_image(game_man->mlx, game_man->images.collectible);
	mlx_destroy_image(game_man->mlx, game_man->images.exit_off);
	mlx_destroy_image(game_man->mlx, game_man->images.exit_on);
	mlx_destroy_image(game_man->mlx, game_man->images.ground);
	mlx_destroy_image(game_man->mlx, game_man->images.player);
	mlx_destroy_image(game_man->mlx, game_man->images.wall);
	mlx_destroy_window(game_man->mlx, game_man->mlx_window);
	mlx_destroy_display(game_man->mlx);
	free(game_man->mlx);
	free_array(game_man->map, game_man->y_size);
	exit(0);
}

void	end_game(t_game_man *game_man)
{
	ft_printf("\n\nCongratulations!!!!!!\n");
	ft_printf("You've reached the exit within %d movements\n",
		game_man->movements);
	ft_printf("Play again to try to do less moves\nGood luck =)\n\n\n");
	close_game(game_man);
}

void	set_game(t_game_man *game_man, t_map_man *map_man)
{
	ft_setmap_game(game_man, map_man);
	game_man->mlx = mlx_init();
	set_sprites(game_man);
	game_man->mlx_window = mlx_new_window(game_man->mlx,
			game_man->x_size * 64, game_man->y_size * 64, "so_long");
	ft_get_exit_position(game_man);
	game_man->cp_y = map_man->p_y;
	game_man->cp_x = map_man->p_x;
	game_man->movements = 0;
	build_sprites(game_man);
	game_man->max_c = map_man ->n_collectibles;
	game_man->current_c = 0;
	ft_printf("Movements: %d\n", game_man->movements);
}

void	game_man(t_game_man *game_man)
{
	mlx_key_hook(game_man->mlx_window, keyhook_handler, game_man);
	mlx_hook(game_man->mlx_window, 17, 0, close_game, game_man);
	mlx_loop(game_man->mlx);
}
