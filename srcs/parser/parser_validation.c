#include "../../includes/cub3d.h"

int validate_config(t_game *game)
{
	if (!game->config.no_texture || !game->config.so_texture ||
		!game->config.we_texture || !game->config.ea_texture)
		return (error_msg("Missing texture definition"));
	
	if (game->config.floor_color == 0 && game->config.ceiling_color == 0)
		return (error_msg("Missing color definition"));
	
	if (!game->config.map || game->config.map_height == 0)
		return (error_msg("Missing or empty map"));
	
	if (!validate_map(game))
		return (0);
	
	return (1);
}

int validate_map(t_game *game)
{
	int player_count = 0;
	int y = 0;
	int x;
	
	// Compter les joueurs
	while (y < game->config.map_height)
	{
		x = 0;
		while (game->config.map[y][x])
		{
			if (game->config.map[y][x] == 'N' || game->config.map[y][x] == 'S' ||
				game->config.map[y][x] == 'E' || game->config.map[y][x] == 'W')
				player_count++;
			x++;
		}
		y++;
	}
	
	if (player_count != 1)
		return (error_msg("Map must have exactly one player"));
	
	if (!is_map_closed(game->config.map, game->config.map_height))
		return (error_msg("Map must be closed by walls"));
	
	return (1);
}

int is_map_closed(char **map, int height)
{
	int y = 0;
	int x;
	int line_len;
	
	// Vérifier les bords
	while (y < height)
	{
		x = 0;
		line_len = ft_strlen(map[y]);
		
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' ||
				map[y][x] == 'E' || map[y][x] == 'W')
			{
				// Vérifier si c'est sur les bords
				if (y == 0 || y == height - 1)
					return (0);
				
				if (x == 0 || x == line_len - 1 || map[y][x + 1] == '\n')
					return (0);
				
				// Vérifier les espaces autour
				if (map[y][x + 1] == ' ')
					return (0);
				
				if (x > 0 && map[y][x - 1] == ' ')
					return (0);
				
				// Vérifier ligne au-dessus et en-dessous
				if (y > 0 && (x >= (int)ft_strlen(map[y - 1]) || 
					map[y - 1][x] == ' ' || map[y - 1][x] == '\n'))
					return (0);
				
				if (y < height - 1 && (x >= (int)ft_strlen(map[y + 1]) || 
					map[y + 1][x] == ' ' || map[y + 1][x] == '\n'))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
