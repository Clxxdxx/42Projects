#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64
# include "libft/libft.h"
# include "fcntl.h"
# include "minilibx-linux/minilibx-linux/mlx.h"

typedef struct s_game
{
    void    *mlx;
    void    *win;

    char    **map;
    int     map_width;
    int     map_height;

    int     player_x;
    int     player_y;
    int     moves;

    void    *img_wall;
    void    *img_floor;
    void    *img_player;
    void    *img_exit;
    void    *img_collectible;
}   t_game;

//MAP ACTIONS
void read_map(t_game *game, const char *filename);
void load_map(t_game *game);
void load_images(t_game *game);

//WINDOW ACTIONS
int close_window(t_game *game);


#endif