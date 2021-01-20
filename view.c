#include "cub3d.h"

void    draw_verline(int x, t_param *p, int color)
{
    int i;

    i = p->draw.drawStart;
    while (i <= p->draw.drawEnd)
    {
        my_mlx_pixel_put(p, x, i, color);
        i++;
    }
}

void    line_wall(t_param *p, int x)
{
    int color;

    p->draw.lineHeight = (int)(p->win_height / p->horizon.perpwalldist);
    p->draw.drawStart = -p->draw.lineHeight / 2 + p->win_height / 2;
    if (p->draw.drawStart < 0)
        p->draw.drawStart = 0;
    p->draw.drawEnd = p->draw.lineHeight / 2 + p->win_height / 2;
    if (p->draw.drawEnd >= p->win_height)
        p->draw.drawEnd = p->win_height - 1;
    color = p->colors.wall;
    if (p->horizon.side == 1)
        color = p->colors.wall / 2;
    draw_verline(x, p, color);  
}

void put_floorsky(t_param *p)
{
    int i;
    int j;
    char *dst;

    i = 0;
    while (i < p->win_width)
    {
	    j = 0;
	    while (j < p->win_height / 2)
	    {
            my_mlx_pixel_put(p, i, j, p->colors.sky);
	        j++;
	    }
	    i++;
    }
    i = 0;
    while (i < p->win_width)
    {
	    j = p->win_height / 2;
	    while (j < p->win_height)
	    {
            my_mlx_pixel_put(p, i, j, p->colors.floor);
	        j++;
	    }
	    i++;
    }
    mlx_put_image_to_window(p->vars.mlx_ptr, p->vars.win_ptr, p->img.img, 0, 0);
}
