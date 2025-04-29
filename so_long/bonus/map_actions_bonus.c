/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:45:13 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/25 15:08:33 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 64, y
			* 64);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * 64, y
			* 64);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 64,
			y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 64, y
			* 64);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x
			* 64, y * 64);
	else if (tile == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, x * 64, y
			* 64);
}

void	load_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	read_map(t_game *game, const char *filename)
{
	int		fd;
	char	*line;
	int		i;

	game->map_height = count_lines(filename);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	game->map_width = ft_strlen(game->map[0]);
	close(fd);
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &w,
			&h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm", &w,
			&h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &w,
			&h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"imgs/collectible.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm", &w,
			&h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "imgs/enemy.xpm", &w,
			&h);
	if (!game->img_wall || !game->img_player || !game->img_exit
		|| !game->img_collectible || !game->img_floor)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
