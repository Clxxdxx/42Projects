/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:45:45 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/25 10:58:16 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free_map(game->map);
	exit(0);
	return (0);
}
