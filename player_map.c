#include "cub3d.h"

/*void	line_dir(t_param *p, int x, int y, int color)
{
    p->fps.x + cos(p->fps.rot_angle) * 30;
    p->fps.y + cos(p->fps.rot_angle) * 30;
    my_mlx_pixel_put(p, p->fps.x, p->fps.y, color);
}*/

void	display_circle_map(t_param *p, int x, int y, int width)
{
    int	i;
    int j;
    double dist;

    p->fps.rad = 3;
    p->horizon.posX = x + 0.5;
    p->horizon.posX = y + 0.5;
    p->colors.person = creat_trgb(0, 255, 255, 255);
    display_cub_map(p, p->colors.floor, x, y, width);
    j = 0;
    while (j <= 2 * p->fps.rad)
    {
	    i = 0;
        while (i <= 2 * p->fps.rad)
        {
            dist = sqrt((i - p->fps.rad) * (i - p->fps.rad) + (j - p->fps.rad) * (j - p->fps.rad));
            if (dist > (p->fps.rad - 0.5) && dist < (p->fps.rad + 0.5))
            {    
                my_mlx_pixel_put(p, i+x, j+y, p->colors.person);		
               // line_dir(p, x, y, p->colors.person);
            }
            i++;
        }
        j++;
    }	
}