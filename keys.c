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
        x++;
    }
    mlx_put_image_to_window(p->vars.mlx_ptr, p->vars.win_ptr, p->img.img, 0, 0);
//	mlx_destroy_image(p->vars.mlx_ptr, p->img.img);
    return (0);
}

int    get_update(t_param *p)
{
    move(p);
    update_scene(p);
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
        p->fps.rotleft = 0;
    if (keycode == ROT_RIGHT)
        p->fps.rotright = 0;
    return (0);
}

int	key_press(int keycode, t_param *p)
{
    static int touch;
    if (keycode == DISP_MAP)
    {   
    //    update_scene(p);
	    touch = (touch + 1) % 2;
	    if (touch % 2 == 1)
            my_cub_map(p);
    }
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
        p->fps.rotleft = 1;
    if (keycode == ROT_RIGHT)
        p->fps.rotright = 1;
  /*  printf("forward %d\n", p->fps.forward);
    printf("backward %d\n", p->fps.backward);
    printf("left %d\n", p->fps.left);
    printf("right %d\n", p->fps.right);*/
    return (0);
}
