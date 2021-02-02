#include "cub3d.h"

int    update_scene(t_param *p)
{
    int x;

    x = 0;
    put_floorsky(p);
    while (x < p->win_width)
    {
        stepX(p, x);
        ft_is_wall(p);
        wall_dist(p);
        line_wall(p, x);
        sprite_casting(p);
        x++;
    }
    return (0);
}

int    get_update(t_param *p)
{
    move(p);
    update_scene(p);
    if (p->touch % 2 == 1)
        my_tiny_map(p);
    return (0);
}

int	key_release(int keycode, t_param *p)
{
    if (keycode == GO_FORWARD)
        p->fps.forward = 0;
    if (keycode == GO_DOWN)
        p->fps.backward = 0;
    if (keycode == GO_LEFT)
        p->fps.left = 0;
    if (keycode == GO_RIGHT)
        p->fps.right = 0;
    if (keycode == ROT_LEFT)
        p->fps.rot_left = 0;
    if (keycode == ROT_RIGHT)
        p->fps.rot_right = 0;
    return (0);
}

int	key_press(int keycode, t_param *p)
{
    if (keycode == ESC)
        quit(p, "Closing the window.\n");
    if (keycode == GO_FORWARD)
        p->fps.forward = 1;
    if (keycode == GO_DOWN)
        p->fps.backward = 1;
    if (keycode == GO_LEFT)
        p->fps.left = 1;
    if (keycode == GO_RIGHT)
        p->fps.right = 1;
    if (keycode == ROT_LEFT)
        p->fps.rot_left = 1;
    if (keycode == ROT_RIGHT)
        p->fps.rot_right = 1;
    if (keycode == DISP_MAP)
    {
	    p->touch = (p->touch + 1) % 2;
	    if (p->touch % 2 == 1)
            my_tiny_map(p);
    }
    return (0);
}
