#include "../../includes/cub3d.h"

void perform_dda(t_game *game, t_ray *ray)
{
    while (ray->hit == 0)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        
        if (ray->map_y < 0 || ray->map_y >= game->config.map_height ||
            ray->map_x < 0 || ray->map_x >= (int)ft_strlen(game->config.map[ray->map_y]))
            break;
        
        if (game->config.map[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
}

void calculate_wall_properties(t_game *game, t_ray *ray)
{
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->map_x - game->player.pos_x +
                               (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->perp_wall_dist = (ray->map_y - game->player.pos_y +
                               (1 - ray->step_y) / 2) / ray->ray_dir_y;
    
    ray->line_height = (int)(game->height / ray->perp_wall_dist);
    
    ray->draw_start = -ray->line_height / 2 + game->height / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    
    ray->draw_end = ray->line_height / 2 + game->height / 2;
    if (ray->draw_end >= game->height)
        ray->draw_end = game->height - 1;
    
    // Calculer wall_x
    if (ray->side == 0)
        ray->wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        ray->wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    ray->wall_x -= floor(ray->wall_x);
}
