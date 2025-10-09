#include "../../includes/cub3d.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        move_forward(game, MOVE_SPEED);
    else if (keycode == KEY_S)
        move_backward(game, MOVE_SPEED);
    else if (keycode == KEY_A)
        move_left(game, MOVE_SPEED);
    else if (keycode == KEY_D)
        move_right(game, MOVE_SPEED);
    else if (keycode == KEY_LEFT)
        rotate_left(game, ROT_SPEED);
    else if (keycode == KEY_RIGHT)
        rotate_right(game, ROT_SPEED);
    else if (keycode == KEY_ESC)
        exit_game(game);
    
    return (0);
}
