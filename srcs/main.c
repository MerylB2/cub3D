#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_game  game;

    if (argc != 2)
        return (error_msg("Usage: ./cub3d <map.cub>"));
    
    // Initialisation de la structure
    memset(&game, 0, sizeof(t_game));
    
    // Parsing de la configuration
    if (!parse_config(argv[1], &game))
        return (1);
    
    // Validation
    if (!validate_config(&game))
        return (free_config(&game), 1);
    
    // Initialisation du jeu
    if (!init_game(&game))
        return (free_config(&game), 1);
    
    // Boucle de jeu
    mlx_hook(game.win, 17, 0, close_window, &game);
    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_loop_hook(game.mlx, render_frame, &game);
    mlx_loop(game.mlx);
    
    return (0);
}
