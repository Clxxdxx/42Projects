#include "../so_long.h"

void load_map(t_game *game)
{
    int y = 0;

    while (y < game->map_height)
    {
        int x = 0;
        while (x < game->map_width)
        {
            char p = game->map[y][x];
            if (p == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 64, y * 64);
            else if (p == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * 64, y * 64);
            else if (p == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 64, y * 64);
            else if (p == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 64, y * 64);
            else if (p == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * 64, y * 64);
            x++;
        }
        y++;
    }
}
void read_map(t_game *game, const char *filename)
{
    int     fd;
    char    *line;
    int     i;
    
    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
        
    game->map = malloc(sizeof(char *) * 100);

    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i] = ft_strtrim(line, "\n");
        free(line);
        i++;
    }
    game->map[i] = NULL;
    game->map_height = i;
    game->map_width = ft_strlen(game->map[0]);
    close(fd);
}

void load_images(t_game *game)
{
    int w;
    int h;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &w, &h);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &w, &h);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &w, &h);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "images/donut2.xpm", &w, &h);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &w, &h);
    if (!game->img_wall || !game->img_player || !game->img_exit
        || !game->img_collectible || !game->img_floor)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
}
