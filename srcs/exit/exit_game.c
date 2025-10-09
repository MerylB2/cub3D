#include "../../includes/cub3d.h"

int close_window(t_game *game)
{
    exit_game(game);
    return (0);
}

int exit_game(t_game *game)
{
    free_textures(game);
    
    if (game->img)
        mlx_destroy_image(game->mlx, game->img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    
    free_config(game);
    
    exit(0);
    return (0);
}
