/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:47:22 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/29 11:37:59 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	show_map_error(t_game *game, int player_x, int player_y)
{
	if (is_valid_map(game->map, 0, 0, 0) == 0)
	{
		ft_putstr_fd("Map is invalid\n", 2);
		free_map(game->map);
		exit(1);
	}
	if (is_rectangular(game->map) == 0)
	{
		ft_putstr_fd("Map isn't rectangular\n", 2);
		free_map(game->map);
		exit(1);
	}
	if (is_valid_wall(game->map) == 0)
	{
		ft_putstr_fd("Map wall is invalid\n", 2);
		free_map(game->map);
		exit(1);
	}
	if (is_road_valid(game->map, game->map_height, player_x, player_y) == 0)
	{
		ft_putstr_fd("Map hasn't got a valid road\n", 2);
		free_map(game->map);
		exit(1);
	}
}
