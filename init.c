#include "cub3d.h"

void	init_img(t_param *p)
{
	p->colors.wall = creat_trgb(0, 47, 95, 95);
    p->colors.floor = creat_trgb(1, p->colors.floor_r, p->colors.floor_g, p->colors.floor_b);
    p->colors.sky = creat_trgb(0, p->colors.sky_r, p->colors.sky_g, p->colors.sky_b);
    p->colors.sprite = creat_trgb(0, 153, 0, 26);
}

void	init_player(t_param *p)
{
    p->map.tab = NULL;
    p->horizon.movespeed =  0.08;
    p->horizon.rotspeed =  0.03;
    p->touch = 0;
    p->sprite.num_sprites = 0;
}