#include "../../includes/cub3d.h"

int check_collision(t_game *game, double new_x, double new_y)
{
    int map_x;
    int map_y;
    
    map_x = (int)new_x;
    map_y = (int)new_y;
    
    if (map_y < 0 || map_y >= game->config.map_height ||
        map_x < 0 || map_x >= (int)ft_strlen(game->config.map[map_y]))
        return (1);
    
    if (game->config.map[map_y][map_x] == '1')
        return (1);
    
    return (0);
}

void move_forward(t_game *game, double speed)
{
    double new_x;
    double new_y;
    
    new_x = game->player.pos_x + game->player.dir_x * speed;
    new_y = game->player.pos_y + game->player.dir_y * speed;
    
    if (!check_collision(game, new_x, game->player.pos_y))
        game->player.pos_x = new_x;
    if (!check_collision(game, game->player.pos_x, new_y))
        game->player.pos_y = new_y;
}

void move_backward(t_game *game, double speed)
{
    double new_x;
    double new_y;
    
    new_x = game->player.pos_x - game->player.dir_x * speed;
    new_y = game->player.pos_y - game->player.dir_y * speed;
    
    if (!check_collision(game, new_x, game->player.pos_y))
        game->player.pos_x = new_x;
    if (!check_collision(game, game->player.pos_x, new_y))
        game->player.pos_y = new_y;
}

void move_left(t_game *game, double speed)
{
    double new_x;
    double new_y;
    
    new_x = game->player.pos_x - game->player.plane_x * speed;
    new_y = game->player.pos_y - game->player.plane_y * speed;
    
    if (!check_collision(game, new_x, game->player.pos_y))
        game->player.pos_x = new_x;
    if (!check_collision(game, game->player.pos_x, new_y))
        game->player.pos_y = new_y;
}

void move_right(t_game *game, double speed)
{
    double new_x;
    double new_y;
    
    new_x = game->player.pos_x + game->player.plane_x * speed;
    new_y = game->player.pos_y + game->player.plane_y * speed;
    
    if (!check_collision(game, new_x, game->player.pos_y))
        game->player.pos_x = new_x;
    if (!check_collision(game, game->player.pos_x, new_y))
        game->player.pos_y = new_y;
}
