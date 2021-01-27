#include "cub3d.h"

void    init_rotTime(t_param *p)
{
    p->horizon.oldtime = p->horizon.time;
    p->horizon.frameTime = (p->horizon.time -  p->horizon.oldtime) / 1000.0;
    p->horizon.movespeed =  p->horizon.frameTime * 5.0;
    p->horizon.rotspeed =  p->horizon.frameTime * 3.0;
}

void    draw_verline(int x, t_param *p, int color)
{
    int i;

    i = p->draw.draw_start;
    while (i <= p->draw.draw_end)
    {
        my_mlx_pixel_put(p, x, i, color);
        i++;
    }
}

void    choose_wall_dir(t_param *p)
{
    if (p->text.wall_dir == 'N')
    {
        p->text.img_addr = p->text.no_addr;
        p->text.tex_width = p->text.no_width;
        p->text.tex_height = p->text.no_height;
    }
    else if (p->text.wall_dir == 'S')
    {
        p->text.img_addr = p->text.so_addr;
        p->text.tex_width = p->text.so_width;
        p->text.tex_height = p->text.so_height;
    }
    else if (p->text.wall_dir == 'W')
    {
        p->text.img_addr = p->text.we_addr;
        p->text.tex_width = p->text.we_width;
        p->text.tex_height = p->text.we_height;
    }
    else if (p->text.wall_dir == 'E')
    {
        p->text.img_addr = p->text.ea_addr;
        p->text.tex_width = p->text.ea_width;
        p->text.tex_height = p->text.ea_height;
    }
}

void    wall_tex_value(t_param *p, int x)
{
    int y;
    int color;

    p->text.tex_num = p->map.tab[p->horizon.currentposY][p->horizon.currentposX] - 1;
    if (p->horizon.side == 0)
        p->text.wallX = p->horizon.posY + p->horizon.perpwalldist * p->horizon.rayDirY;
    else
        p->text.wallX = p->horizon.posX + p->horizon.perpwalldist * p->horizon.rayDirX;
    p->text.wallX -= floor((p->text.wallX));
    p->text.texX = (int)(p->text.wallX * (double)p->text.tex_width);
    if (p->horizon.side == 0)
    {
        if (p->horizon.rayDirX > 0)
            p->text.wall_dir = 'N';
        else
            p->text.wall_dir = 'S';
    }
    if (p->horizon.side == 1)
    {
        if (p->horizon.rayDirX < 0)
            p->text.wall_dir = 'W';
        else
            p->text.wall_dir = 'E';
    }
    p->text.texX = p->text.tex_width - p->text.texX - 1;
    p->text.step = 1.0 * p->text.tex_height / p->draw.line_height;
    p->text.tex_pos = (p->draw.draw_start - p->win_height / 2 + p->draw.line_height / 2) * p->text.step;
    choose_wall_dir(p);
    color = 0;
    y = p->draw.draw_start;
    while (y < p->draw.draw_end)
    {
        p->text.texY = (int)p->text.tex_pos & p->text.tex_height - 1;
        p->text.tex_pos += p->text.step;
        color = p->text.img_addr[p->text.tex_height * p->text.texY + p->text.texX];
        if (p->horizon.side == 1)
            color = (color >> 1) & 8355711;
        my_mlx_pixel_put(p, x, y, color);
        y++;
    }
}

void    line_wall(t_param *p, int x)
{
    int color;

    p->draw.line_height = (int)(p->win_height / p->horizon.perpwalldist);
    p->draw.draw_start = -p->draw.line_height / 2 + p->win_height / 2;
    if (p->draw.draw_start < 0)
        p->draw.draw_start = 0;
    p->draw.draw_end = p->draw.line_height / 2 + p->win_height / 2;
    if (p->draw.draw_end >= p->win_height)
        p->draw.draw_end = p->win_height - 1;
    color = p->colors.wall;
    if (p->horizon.side == 1)
        color = p->colors.wall / 2;
  // draw_verline(x, p, color);
   wall_tex_value(p, x);
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
