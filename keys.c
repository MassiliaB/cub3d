#include "cub3d.h"

int	put_image(t_param *p)
{
    int i;
    int j;

    i = 0;
    while (i < p->win_width)
    {
	    j = 0;
	    while (j < p->win_height)
	    {
	        my_mlx_pixel_put(p, i, j, 9028852);
	        j++;
	    }
	    i++;
    }
    mlx_put_image_to_window(p->vars.mlx_ptr, p->vars.win_ptr, p->img.img, 0, 0);
    return (1);
}

int ft_uptade(t_param *p)
{
    if ()

}

int	keygen(int keycode, t_param *p)
{
    static int touch;
    printf("touch %d\n", keycode);
    if (keycode == DISP_MAP)
    {
        put_image(p); 
	    touch = (touch + 1) % 2;
	    if (touch % 2 == 1)
            my_cub_map(p);
    }
    ft_uptade(p);
    if (keycode == ESC)
        exit(0);
    return (1);
}
