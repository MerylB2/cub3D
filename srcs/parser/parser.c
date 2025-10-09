#include "../../includes/cub3d.h"

static int is_empty_line(char *line)
{
    int i = 0;
    
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

int parse_config(char *filename, t_game *game)
{
    int     fd;
    char    *line;
    int     reading_map;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (error_msg("Cannot open file"));
    
    reading_map = 0;
    while ((line = get_next_line(fd)))
    {
        if (is_empty_line(line))
        {
            free(line);
            continue;
        }
        
        if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
            reading_map = 1;
        
        if (!reading_map)
        {
            if (!parse_line(line, game))
            {
                free(line);
                close(fd);
                return (0);
            }
        }
        else
        {
            if (!parse_map_line(line, game))
            {
                free(line);
                close(fd);
                return (0);
            }
        }
        free(line);
    }
    close(fd);
    return (1);
}

int parse_line(char *line, t_game *game)
{
    char *trimmed = ft_strtrim(line, " \t\n");
    int result = 1;
    
    if (!trimmed)
        return (0);
    
    if (ft_strncmp(trimmed, "NO ", 3) == 0)
        result = parse_texture(trimmed + 3, &game->config.no_texture);
    else if (ft_strncmp(trimmed, "SO ", 3) == 0)
        result = parse_texture(trimmed + 3, &game->config.so_texture);
    else if (ft_strncmp(trimmed, "WE ", 3) == 0)
        result = parse_texture(trimmed + 3, &game->config.we_texture);
    else if (ft_strncmp(trimmed, "EA ", 3) == 0)
        result = parse_texture(trimmed + 3, &game->config.ea_texture);
    else if (ft_strncmp(trimmed, "F ", 2) == 0)
        result = parse_color(trimmed + 2, &game->config.floor_color);
    else if (ft_strncmp(trimmed, "C ", 2) == 0)
        result = parse_color(trimmed + 2, &game->config.ceiling_color);
    
    free(trimmed);
    return (result);
}
