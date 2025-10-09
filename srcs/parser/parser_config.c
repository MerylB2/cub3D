#include "../../includes/cub3d.h"

int parse_texture(char *line, char **texture_path)
{
    char *trimmed = ft_strtrim(line, " \t\n");
    
    if (!trimmed)
        return (error_msg("Texture path allocation failed"));
    
    if (*texture_path)
    {
        free(trimmed);
        return (error_msg("Duplicate texture definition"));
    }
    
    *texture_path = trimmed;
    return (1);
}

static int parse_rgb_value(char *str)
{
    int value = ft_atoi(str);
    
    if (value < 0 || value > 255)
        return (-1);
    return (value);
}

int parse_color(char *line, int *color)
{
    char    **rgb;
    int     r, g, b;
    char    *trimmed;
    
    trimmed = ft_strtrim(line, " \t\n");
    if (!trimmed)
        return (0);
    
    rgb = ft_split(trimmed, ',');
    free(trimmed);
    
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
    {
        // Free rgb array
        return (error_msg("Invalid color format (need R,G,B)"));
    }
    
    r = parse_rgb_value(rgb[0]);
    g = parse_rgb_value(rgb[1]);
    b = parse_rgb_value(rgb[2]);
    
    // Free rgb array here
    
    if (r < 0 || g < 0 || b < 0)
        return (error_msg("RGB values must be 0-255"));
    
    *color = (r << 16) | (g << 8) | b;
    return (1);
}
