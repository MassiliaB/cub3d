#include "cub3d.h"

int	put_image(t_param *p)
{

    mlx_put_image_to_window(p->vars.mlx_ptr, p->vars.win_ptr, p->img.img, 0, 0);
    return (1);
}

int	keygen(int keycode, t_param *p)
{
    if (keycode == DISP_MAP)
	my_cub_map(p);
    put_image(p); 
    return (1);
}
