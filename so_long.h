/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:05:21 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/18 11:26:12 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define WALL_IMG "textures/Wall.xpm"
# define EXITOFF_IMG "textures/Exit_off.xpm"
# define EXITON_IMG "textures/Exit_on.xpm"
# define GROUND_IMG "textures/Ground.xpm"
# define PLAYER_IMG "textures/Player.xpm"
# define COLLECTIBLE_IMG "textures/Collectible.xpm"

typedef struct s_map_man
{
	size_t	x_size;
	size_t	y_size;
	char	**map;
	char	*map_name;
	int		map_fd;
	int		p_x;
	int		p_y;
	int		n_collectibles;
	int		n_collectibles_access;
	int		exit_access;
}	t_map_man;

typedef struct s_images
{
	void	*player;
	void	*wall;
	void	*exit_off;
	void	*exit_on;
	void	*collectible;
	void	*ground;
}	t_images;

typedef struct s_game_man
{
	t_images	images;
	char		**map;
	void		*mlx;
	void		*mlx_window;
	int			x_size;
	int			y_size;
	int			cp_x;
	int			cp_y;
	int			movements;
	int			current_c;
	int			max_c;
	int			exit_x;
	int			exit_y;
}	t_game_man;

void	*get_sprite(t_game_man *game_man, int x_pos, int y_pos);
void	ft_getplayerstartposition(t_map_man *map_man);
void	ft_get_exit_position(t_game_man *game);
void	ft_flood_fill(char **map, int p_y, int p_x, t_map_man *map_man);
void	set_game(t_game_man *game_man, t_map_man *map_man);
void	game_man(t_game_man *game_man);
void	set_sprites(t_game_man *game_man);
void	build_sprites(t_game_man *game_man);
void	move_player(t_game_man *game, char move);
void	free_array(char **map, int y_size);
void	end_game(t_game_man *game_man);
void	put_str_window(t_game_man *game);
int		close_game(t_game_man *game_man);
int		keyhook_handler(int keycode, t_game_man *game_man);
int		ft_main_check(int argc, char *argv[], t_map_man *s_map_man);
int		ft_check_args(int argc);
int		ft_check_mapextension(char *name);
int		ft_check_mapexist(char *name, t_map_man *s_map_man);
int		ft_check_mapshape(t_map_man *s_map_man);
int		ft_checkwalls(t_map_man *s_map_man);
int		ft_check_tiles(t_map_man *map_man);
int		ft_check_entities(t_map_man *map_man);
int		ft_checksolvable(t_map_man *map_man);
int		ft_help_checkentities(t_map_man *map_man, char entity);
int		ft_setmap_check(t_map_man *map_man);
int		ft_setmap_game(t_game_man *game_man, t_map_man *map_man);

#endif