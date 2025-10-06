#ifndef STRUCTS_H
# define STRUCTS_H

# include "keys.h"

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

/* Constantes de jeu */
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03
# define TEX_WIDTH 64
# define TEX_HEIGHT 64


/* Struct for one texture */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

/* Struct for game textures */
typedef struct s_textures
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
}	t_textures;

/* Struct colors */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	encoded;
}	t_color;

/* Struct map */
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

/* Struct for player */
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

/* Struct raycasting */
typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_num;
}	t_ray;

/* Structure MLX */
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

/* Principal struct for game */
typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_textures	textures;
	t_color		floor;
	t_color		ceiling;
	int			**texture_data;
}	t_game;

#endif