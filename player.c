#include "cub3d.h"

void	render_player(t_param *p)
{

    

}

void	init_player(t_param *p)
{
    p->fps.rad = 3;
    p->fps.dir_turn = 0;
    p->fps.dir_walk = 0;
    p->fps.rot_angle = M_PI / 2;
    p->fps.move_speed = 2.0;
    p->fps.rot_speed = 2 * (M_PI / 180);

   // render_player();
}

void	display_circle(t_param *p, int color, int x, int y)
{
    int	i;
    int j;
    double dist;

    i = 0;
    while (i <= 2 * p->fps.rad)
    {
	j = 0;
	while (j <= 2 * p->fps.rad)
	{
	    dist = sqrt((i - p->fps.rad) * (i - p->fps.rad) + (j - p->fps.rad) * (j - p->fps.rad));
	  if (dist > (p->fps.rad - 0.5) && dist < (p->fps.rad + 0.5))
		my_mlx_pixel_put(p, x, y, color);
	    j++;
	}
	i++;
    }	
}
