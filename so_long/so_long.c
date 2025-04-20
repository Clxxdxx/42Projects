#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (write(2, "Error1\n", 6));

    game.mlx = mlx_init();

    read_map(&game, argv[1]);

    game.win = mlx_new_window(game.mlx, game.map_width * 64, game.map_height * 64, "so_long");

    load_images(&game);

    load_map(&game);
    mlx_hook(game.win, 17, 0, close_window, &game);
    mlx_loop(game.mlx);
    return (0);
}
