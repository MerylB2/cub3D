#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		print_error("Usage: ./cub3d <map.cub>");
		return (1);
	}
	/* Vérifier l'extension .cub */
	if (!check_file_extension(argv[1], ".cub"))
	{
		print_error("Invalid file extension (must be .cub)");
		return (1);
	}
	
	/* Initialisation complète du jeu */
	if (!init_game(&game, argv[1]))
	{
		free_game(&game);
		return (1);
	}
	
	/* Lancer la boucle de jeu */
	mlx_loop_hook(game.mlx.mlx, &render_frame, &game);
	mlx_hook(game.mlx.win, 2, 1L << 0, &key_press, &game);
	mlx_hook(game.mlx.win, 17, 0, &exit_game, &game);
	mlx_loop(game.mlx.mlx);
	
	return (0);
}
