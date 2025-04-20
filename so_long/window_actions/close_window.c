#include "../so_long.h"

int close_window(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img_collectible);
    mlx_destroy_image(game->mlx, game->img_floor);
    mlx_destroy_image(game->mlx, game->img_wall);
    mlx_destroy_image(game->mlx, game->img_exit);
    mlx_destroy_image(game->mlx, game->img_player);
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return(0);
}