#include "../../includes/cub3d.h"

int init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (error_msg("MLX initialization failed"));
    
    game->win = mlx_new_window(game->mlx, game->width, game->height, "Cub3D");
    if (!game->win)
        return (error_msg("Window creation failed"));
    
    game->img = mlx_new_image(game->mlx, game->width, game->height);
    if (!game->img)
        return (error_msg("Image creation failed"));
    
    game->addr = mlx_get_data_addr(game->img, &game->bpp,
                                   &game->line_len, &game->endian);
    
    return (1);
}
