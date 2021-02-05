#include "cub3d.h"

void	line_dir(t_param *p, int x, int y, int color)
{
    p->fps.x = x + cos(p->fps.rot_angle) * 30;
    p->fps.y = y + cos(p->fps.rot_angle) * 30;
    my_mlx_pixel_put(p, p->fps.x, p->fps.y, color);
}

