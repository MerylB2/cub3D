#include "../../includes/cub3d.h"

void my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
    char    *dst;
    
    if (x < 0 || x >= game->width || y < 0 || y >= game->height)
        return;
    
    dst = game->addr + (y * game->line_len + x * (game->bpp / 8));
    *(unsigned int *)dst = color;
}

void draw_ceiling(t_game *game, int x, int y_start, int y_end)
{
    int y;
    
    y = y_start;
    while (y < y_end)
    {
        my_mlx_pixel_put(game, x, y, game->config.ceiling_color);
        y++;
    }
}

void draw_floor(t_game *game, int x, int y_start, int y_end)
{
    int y;
    
    y = y_start;
    while (y < y_end)
    {
        my_mlx_pixel_put(game, x, y, game->config.floor_color);
        y++;
    }
}

int render_frame(t_game *game)
{
    raycasting(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return (0);
}
