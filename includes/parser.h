#ifndef PARSER_H
# define PARSER_H

# include "structs.h"

int		parse_file(char *filename, t_game *game);
int		parse_config_line(char *line, t_game *game, int *config_flags);
int		parse_map(int fd, t_game *game);
int		parse_color(char *str, t_color *color);
int		validate_map(t_game *game);

/* ===== RENDER ===== */
void	render_frame(t_game *game);
void	render_floor_ceiling(t_game *game);
void	render_walls(t_game *game, t_ray *ray, int x);
void	draw_texture_column(t_game *game, t_ray *ray, int x);

#endif