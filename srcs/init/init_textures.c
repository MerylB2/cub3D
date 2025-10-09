#include "../../includes/cub3d.h"

static int load_texture(t_game *game, t_texture *tex, char *path)
{
    tex->img = mlx_xpm_file_to_image(game->mlx, path,
                                     &tex->width, &tex->height);
    if (!tex->img)
    {
        printf("Error: Failed to load texture: %s\n", path);
        return (0);
    }
    
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
                                  &tex->line_len, &tex->endian);
    return (1);
}

int init_textures(t_game *game)
{
    if (!load_texture(game, &game->textures[TEX_NO], game->config.no_texture))
        return (0);
    if (!load_texture(game, &game->textures[TEX_SO], game->config.so_texture))
        return (0);
    if (!load_texture(game, &game->textures[TEX_WE], game->config.we_texture))
        return (0);
    if (!load_texture(game, &game->textures[TEX_EA], game->config.ea_texture))
        return (0);
    
    return (1);
}
