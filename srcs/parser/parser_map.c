#include "../../includes/cub3d.h"

static void add_to_map(t_game *game, char *line)
{
    char    **new_map;
    int     i;
    int     len;
    
    len = ft_strlen(line);
    if (len > game->config.map_width)
        game->config.map_width = len;
    
    new_map = malloc(sizeof(char *) * (game->config.map_height + 2));
    
    i = 0;
    while (i < game->config.map_height)
    {
        new_map[i] = game->config.map[i];
        i++;
    }
    new_map[i] = ft_strdup(line);
    new_map[i + 1] = NULL;
    
    if (game->config.map)
        free(game->config.map);
    game->config.map = new_map;
    game->config.map_height++;
}

int parse_map_line(char *line, t_game *game)
{
    int i = 0;
    
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != ' ' &&
            line[i] != 'N' && line[i] != 'S' && line[i] != 'E' &&
            line[i] != 'W' && line[i] != '\n')
            return (error_msg("Invalid character in map"));
        i++;
    }
    
    add_to_map(game, line);
    return (1);
}

void find_player_position(t_game *game)
{
    int y = 0;
    int x;
    
    while (y < game->config.map_height)
    {
        x = 0;
        while (game->config.map[y][x])
        {
            if (game->config.map[y][x] == 'N' || game->config.map[y][x] == 'S' ||
                game->config.map[y][x] == 'E' || game->config.map[y][x] == 'W')
            {
                game->player.pos_x = x + 0.5;
                game->player.pos_y = y + 0.5;
                game->player.orientation = game->config.map[y][x];
                game->config.map[y][x] = '0';
                return;
            }
            x++;
        }
        y++;
    }
}
