/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:29:30 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/25 15:32:27 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "fcntl.h"
# include "libft/libft.h"
# include "minilibx-linux/minilibx-linux/mlx.h"
# include <X11/keysymdef.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;
	int		moves;
	int		player_on_exit;

	int		enemy_y;
	int		enemy_x;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*img_enemy;
}			t_game;

void		find_player(char **map, int *x, int *y);
void		find_enemy(char **map, int *x, int *y);
void		free_map(char **map);
int			count_lines(const char *filename);
int			count_collect(char **map);

// MAP ACTIONS
void		read_map(t_game *game, const char *filename);
void		load_map(t_game *game);
void		load_images(t_game *game);

// WINDOW ACTIONS
int			close_window(t_game *game);
void		show_moves(t_game *game);

// ERRORS
int			is_valid_map(char **map, int player_count, int exit_count,
				int collect_count);
int			is_rectangular(char **map);
int			is_valid_wall(char **map);
int			is_road_valid(char **map, int height, int player_x, int player_y);
void		show_map_error(t_game *game, int player_x, int player_y);

// MOVEMENTS
int			move_player(t_game *game, int keycode);

#endif