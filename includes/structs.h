#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_player
{
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
    char    orientation;
}   t_player;

typedef struct s_ray
{
    double  camera_x;
    double  ray_dir_x;
    double  ray_dir_y;
    int     map_x;
    int     map_y;
    double  side_dist_x;
    double  side_dist_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  perp_wall_dist;
    int     step_x;
    int     step_y;
    int     hit;
    int     side;
    int     line_height;
    int     draw_start;
    int     draw_end;
    double  wall_x;
    int     tex_x;
}   t_ray;

typedef struct s_texture
{
    void    *img;
    char    *addr;
    int     width;
    int     height;
    int     bpp;
    int     line_len;
    int     endian;
}   t_texture;

typedef struct s_config
{
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    int     floor_color;
    int     ceiling_color;
    char    **map;
    int     map_width;
    int     map_height;
}   t_config;

typedef struct s_game
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *addr;
    int         bpp;
    int         line_len;
    int         endian;
    t_player    player;
    t_config    config;
    t_texture   textures[4];
    int         width;
    int         height;
}   t_game;

#endif