#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "structs.h"

void	raycasting(t_game *game);
void	init_ray(t_game *game, t_ray *ray, int x);
void	perform_dda(t_game *game, t_ray *ray);
void	calculate_wall_distance(t_ray *ray);
void	calculate_draw_limits(t_ray *ray);
int		select_texture(t_ray *ray);

#endif