#ifndef CUB3D_H
# define CUB3D_H

# include <keys.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "structs.h"

// Dimensions fenêtre
# define WIDTH 1280
# define HEIGHT 720

// Vitesses
# define MOVE_SPEED 0.08
# define ROT_SPEED 0.05

/* Constantes de jeu */
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

// Indices textures
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3

// Prototypes - Init
int         init_game(t_game *game);
int         init_mlx(t_game *game);
int         init_textures(t_game *game);
void        init_player(t_game *game);

// Prototypes - Parser
int         parse_config(char *filename, t_game *game);
int         parse_line(char *line, t_game *game);
int         parse_texture(char *line, char **texture_path);
int         parse_color(char *line, int *color);
int         parse_map_line(char *line, t_game *game);
int         validate_config(t_game *game);
int         validate_map(t_game *game);
int         is_map_closed(char **map, int height);
void        find_player_position(t_game *game);

// Prototypes - Raycasting
void        raycasting(t_game *game);
void        init_ray(t_game *game, t_ray *ray, int x);
void        calculate_step_and_side_dist(t_game *game, t_ray *ray);
void        perform_dda(t_game *game, t_ray *ray);
void        calculate_wall_properties(t_game *game, t_ray *ray);
void        draw_textured_wall(t_game *game, t_ray *ray, int x);
t_texture   *select_texture(t_game *game, t_ray *ray);
int         get_texture_color(t_texture *tex, int x, int y);

// Prototypes - Render
int         render_frame(t_game *game);
void        my_mlx_pixel_put(t_game *game, int x, int y, int color);
void        draw_ceiling(t_game *game, int x, int y_start, int y_end);
void        draw_floor(t_game *game, int x, int y_start, int y_end);

// Prototypes - Controls
int         key_press(int keycode, t_game *game);
void        move_forward(t_game *game, double speed);
void        move_backward(t_game *game, double speed);
void        move_left(t_game *game, double speed);
void        move_right(t_game *game, double speed);
void        rotate_left(t_game *game, double speed);
void        rotate_right(t_game *game, double speed);
int         check_collision(t_game *game, double new_x, double new_y);

// Prototypes - Utils
char        *ft_strdup(const char *s);
char        *ft_substr(char const *s, unsigned int start, size_t len);
char        **ft_split(char const *s, char c);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
int         ft_strlen(const char *s);
char        *ft_strtrim(char const *s1, char const *set);
int         ft_atoi(const char *str);
char        *get_next_line(int fd);

// Prototypes - Error & Exit
int         error_msg(char *msg);
void        free_config(t_game *game);
void        free_textures(t_game *game);
int         exit_game(t_game *game);
int         close_window(t_game *game);

#endif