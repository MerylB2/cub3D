#include "../../includes/cub3d.h"

int init_game(t_game *game)
{
    game->width = WIDTH;
    game->height = HEIGHT;
    
    if (!init_mlx(game))
        return (0);
    
    init_player(game);
    
    if (!init_textures(game))
        return (0);
    
    return (1);
}

void init_player(t_game *game)
{
    find_player_position(game);
    
    if (game->player.orientation == 'N')
    {
        game->player.dir_x = 0;
        game->player.dir_y = -1;
        game->player.plane_x = 0.66;
        game->player.plane_y = 0;
    }
    else if (game->player.orientation == 'S')
    {
        game->player.dir_x = 0;
        game->player.dir_y = 1;
        game->player.plane_x = -0.66;
        game->player.plane_y = 0;
    }
    else if (game->player.orientation == 'E')
    {
        game->player.dir_x = 1;
        game->player.dir_y = 0;
        game->player.plane_x = 0;
        game->player.plane_y = 0.66;
    }
    else if (game->player.orientation == 'W')
    {
        game->player.dir_x = -1;
        game->player.dir_y = 0;
        game->player.plane_x = 0;
        game->player.plane_y = -0.66;
    }
}