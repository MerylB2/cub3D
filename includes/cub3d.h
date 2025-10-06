#ifndef CUB3D_H
# define CUB3D_H

# include "keys.h"
# include "mlx.h"
# include "parser.h"
# include "raycasting.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include "structs.h"

/* ===== INIT ===== */
int		init_game(t_game *game, char *filename);
int		init_mlx(t_game *game);
int		init_textures(t_game *game);

/* ===== CONTROLS ===== */
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

/* ===== UTILS ===== */
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
char	*skip_spaces(char *str);
void	trim_end(char *str);

/* ===== ERROR & EXIT ===== */
void	print_error(char *msg);
int		exit_game(t_game *game);
void	free_game(t_game *game);
void	free_textures(t_game *game);
void	free_map(t_map *map);

#endif
