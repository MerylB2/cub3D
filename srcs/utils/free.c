#include "../../includes/cub3d.h"

void free_config(t_game *game)
{
    int i;
    
    if (game->config.no_texture)
        free(game->config.no_texture);
    if (game->config.so_texture)
        free(game->config.so_texture);
    if (game->config.we_texture)
        free(game->config.we_texture);
    if (game->config.ea_texture)
        free(game->config.ea_texture);
    
    if (game->config.map)
    {
        i = 0;
        while (i < game->config.map_height)
        {
            free(game->config.map[i]);
            i++;
        }
        free(game->config.map);
    }
}

void free_textures(t_game *game)
{
    int i;
    
    i = 0;
    while (i < 4)
    {
        if (game->textures[i].img)
            mlx_destroy_image(game->mlx, game->textures[i].img);
        i++;
    }
}
