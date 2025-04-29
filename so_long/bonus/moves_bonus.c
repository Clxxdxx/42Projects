/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:20:03 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/29 11:04:47 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	is_valid_enemy_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_y >= game->map_height
		|| new_x >= game->map_width)
		return (0);
	if (new_x == game->player_x && new_y == game->player_y)
	{
		write(1, "Has sido atrapado por el enemigo.\n", 34);
		close_window(game);
	}
	if (game->map[new_y][new_x] != '0')
		return (0);
	return (1);
}

void	move_enemies(t_game *game)
{
	int	dir;
	int	new_x;
	int	new_y;

	if (game->enemy_x < 0 || game->enemy_y < 0)
		return ;
	dir = rand() % 4;
	new_x = game->enemy_x;
	new_y = game->enemy_y;
	if (dir == 0)
		new_y--;
	else if (dir == 1)
		new_y++;
	else if (dir == 2)
		new_x--;
	else if (dir == 3)
		new_x++;
	if (!is_valid_enemy_move(game, new_x, new_y))
		return ;
	game->map[game->enemy_y][game->enemy_x] = '0';
	game->map[new_y][new_x] = 'X';
	game->enemy_x = new_x;
	game->enemy_y = new_y;
}

int	update_player_position(t_game *game, int keycode, int *new_x, int *new_y)
{
	*new_x = game->player_x;
	*new_y = game->player_y;
	if (keycode == 65362 || keycode == 'w')
		(*new_y)--;
	else if (keycode == 65364 || keycode == 's')
		(*new_y)++;
	else if (keycode == 65361 || keycode == 'a')
		(*new_x)--;
	else if (keycode == 65363 || keycode == 'd')
		(*new_x)++;
	if (*new_x < 0 || *new_y < 0 || *new_y >= game->map_height
		|| *new_x >= game->map_width)
		return (0);
	if (game->map[*new_y][*new_x] == '1')
		return (0);
	return (1);
}

void	process_movement(t_game *game, int new_x, int new_y, int collect)
{
	char	next_tile;
	int		w;
	int		h;

	if (collect == 0)
		game->img_exit = mlx_xpm_file_to_image(game->mlx, "imgs/e.xpm", &w, &h);
	next_tile = game->map[new_y][new_x];
	if (next_tile == 'E' && collect != 0)
	{
		if (game->player_on_exit)
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->player_on_exit = 1;
	}
	else
	{
		if (game->player_on_exit)
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->player_on_exit = 0;
		if (next_tile == 'E' && collect == 0)
			close_window(game);
	}
}

int	move_player(t_game *game, int keycode)
{
	int	new_x;
	int	new_y;
	int	collect;

	collect = count_collect(game->map);
	if (!update_player_position(game, keycode, &new_x, &new_y))
		return (0);
	if (new_x == game->enemy_x && new_y == game->enemy_y)
		close_window(game);
	process_movement(game, new_x, new_y, collect);
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	show_moves(game);
	load_map(game);
	move_enemies(game);
	if (game->player_x == game->enemy_x && game->player_y == game->enemy_y)
		close_window(game);
	return (0);
}
