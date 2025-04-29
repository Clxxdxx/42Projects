/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:34:35 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/25 15:12:47 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_enemy(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	count = 0;
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

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

void	show_moves(t_game *game)
{
	char	*num;
	int		text_width;
	int		x_text;
	int		y_text;
	int		i;

	game->moves++;
	num = ft_itoa(game->moves);
	text_width = ft_strlen(num) * 10;
	x_text = (game->map_width * 64 - text_width) / 2;
	y_text = game->map_height * 64 + 10;
	i = 0;
	while (i < game->map_width)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, i * 64,
			game->map_height * 64);
		i++;
	}
	mlx_string_put(game->mlx, game->win, x_text - 80, y_text + 15, 0xFFFFFF,
		"Movimientos: ");
	mlx_string_put(game->mlx, game->win, x_text, y_text + 15, 0xFFFFFF, num);
	free(num);
}
