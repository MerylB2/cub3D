#include "../../includes/cub3d.h"

t_texture *select_texture(t_game *game, t_ray *ray)
{
    if (ray->side == 0)
    {
        if (ray->ray_dir_x > 0)
            return (&game->textures[TEX_EA]);
        else
            return (&game->textures[TEX_WE]);
    }
    else
    {
        if (ray->ray_dir_y > 0)
            return (&game->textures[TEX_SO]);
        else
            return (&game->textures[TEX_NO]);
    }
}

int get_texture_color(t_texture *tex, int x, int y)
{
    char    *pixel;
    
    if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
        return (0);
    
    pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
    return (*(int *)pixel);
}

void draw_textured_wall(t_game *game, t_ray *ray, int x)
{
    t_texture   *tex;
    int         tex_x;
    int         tex_y;
    double      step;
    double      tex_pos;
    int         y;
    int         color;
    
    tex = select_texture(game, ray);
    
    tex_x = (int)(ray->wall_x * (double)tex->width);
    if ((ray->side == 0 && ray->ray_dir_x > 0) ||
        (ray->side == 1 && ray->ray_dir_y < 0))
        tex_x = tex->width - tex_x - 1;
    
    step = 1.0 * tex->height / ray->line_height;
    tex_pos = (ray->draw_start - game->height / 2 + ray->line_height / 2) * step;
    
    draw_ceiling(game, x, 0, ray->draw_start);
    
    y = ray->draw_start;
    while (y < ray->draw_end)
    {
        tex_y = (int)tex_pos & (tex->height - 1);
        tex_pos += step;
        color = get_texture_color(tex, tex_x, tex_y);
        
        if (ray->side == 1)
            color = (color >> 1) & 8355711;
        
        my_mlx_pixel_put(game, x, y, color);
        y++;
    }
    
    draw_floor(game, x, ray->draw_end, game->height);
}
