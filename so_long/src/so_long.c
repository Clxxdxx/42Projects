/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:45:51 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/29 11:38:23 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 65361 || keycode == 65362 || keycode == 65363
		|| keycode == 65364 || keycode == 'w' || keycode == 'a'
		|| keycode == 's' || keycode == 'd')
		move_player(game, keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		player_x;
	int		player_y;

	if (argc != 2)
		return (write(2, "Error\n", 6));
	game.mlx = mlx_init();
	game.moves = 0;
	read_map(&game, argv[1]);
	find_player(game.map, &player_x, &player_y);
	game.player_on_exit = 0;
	game.player_x = player_x;
	game.player_y = player_y;
	show_map_error(&game, player_x, player_y);
	game.win = mlx_new_window(game.mlx, game.map_width * 64, game.map_height
			* 64, "so_long");
	load_images(&game);
	load_map(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
