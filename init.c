#include "cub3d.h"

void	ft_init_img(t_param *p)
{
	p->img.bits_per_pixel = 16;
	p->img.line_length = 1;
	p->img.endian = 1;
	p->colors.wall = creat_trgb(0, 47, 95, 95);
    p->colors.floor = creat_trgb(1, p->colors.floor_r, p->colors.floor_g, p->colors.floor_b);
    p->colors.sky = creat_trgb(0, p->colors.sky_r, p->colors.sky_g, p->colors.sky_b);
}

void	init_player(t_param *p)
{
    p->map.tab = NULL;
    p->fps.forward = 0;
    p->fps.backward = 0;
    p->fps.left = 0;
    p->fps.right = 0;
    p->fps.rot_left = 0;
    p->fps.rot_right = 0;
    p->horizon.posX = 0;
    p->horizon.posY = 0;
    p->horizon.movespeed = 0.08;
    p->horizon.rotspeed = 0.02;
    p->horizon.perpwalldist = 0;
    p->horizon.dirX = -1;
    p->horizon.dirY = 0;
    p->horizon.oldtime = 0;
    p->horizon.time = 0;
    p->vars.win_ptr = 0;
    p->horizon.movespeed =  0.08;
    p->horizon.rotspeed =  0.02;
    p->text.no = NULL;
    p->text.so = NULL;
    p->text.we = NULL;
    p->text.ea = NULL;
}