/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:20:03 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/25 15:26:48 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_collect(char **map)
{
	int	y;
	int	x;
	int	collect_count;

	collect_count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collect_count++;
			x++;
		}
		y++;
	}
	return (collect_count);
}

int	update_position(t_game *game, int keycode, int *new_x, int *new_y)
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

void	handle_player_tile(t_game *game, char next_tile, int collect)
{
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
	int		new_x;
	int		new_y;
	int		collect;
	char	next_tile;

	collect = count_collect(game->map);
	if (!update_position(game, keycode, &new_x, &new_y))
		return (0);
	next_tile = game->map[new_y][new_x];
	handle_player_tile(game, next_tile, collect);
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("%d\n", game->moves);
	load_map(game);
	return (0);
}
