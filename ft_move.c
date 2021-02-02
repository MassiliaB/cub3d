#include "cub3d.h"

int moving_ok(char moove)
{
    if (moove == '1' || moove == '2')
        return (0);
    return (1);
}

void    rotate(t_param *p)
{
    p->horizon.oldDirX = p->horizon.dirX;
    p->horizon.oldPlaneX = p->horizon.planeX;
    if (p->fps.rot_right == 1)
    {
        p->horizon.dirX = p->horizon.dirX * cos(-(p->horizon.rotspeed)) - p->horizon.dirY * sin(-(p->horizon.rotspeed));
        p->horizon.dirY = p->horizon.oldDirX * sin(-(p->horizon.rotspeed)) + p->horizon.dirY * cos(-(p->horizon.rotspeed));
        p->horizon.planeX = p->horizon.planeX * cos(-(p->horizon.rotspeed)) - p->horizon.planeY * sin(-(p->horizon.rotspeed));
        p->horizon.planeY = p->horizon.oldPlaneX * sin(-(p->horizon.rotspeed)) + p->horizon.planeY * cos(-(p->horizon.rotspeed));        
    }
    if (p->fps.rot_left == 1)
    {
        p->horizon.dirX = p->horizon.dirX * cos(p->horizon.rotspeed) - p->horizon.dirY * sin(p->horizon.rotspeed);
        p->horizon.dirY = p->horizon.oldDirX * sin(p->horizon.rotspeed) + p->horizon.dirY * cos(p->horizon.rotspeed);
        p->horizon.planeX = p->horizon.planeX * cos(p->horizon.rotspeed) - p->horizon.planeY * sin(p->horizon.rotspeed);
        p->horizon.planeY = p->horizon.oldPlaneX * sin(p->horizon.rotspeed) + p->horizon.planeY * cos(p->horizon.rotspeed);        
    }
    
}

int    move(t_param *p)
{
    if (p->fps.forward == 1)
    {
        if (moving_ok(p->map.tab[(int)(p->horizon.posY)]
        [(int)(p->horizon.posX + p->horizon.dirX * p->horizon.movespeed)]))
            p->horizon.posX += p->horizon.dirX * p->horizon.movespeed * 0.5;
        if (moving_ok(p->map.tab[(int)(p->horizon.posY + p->horizon.dirY * p->horizon.movespeed)]
        [(int)(p->horizon.posX)])) 
            p->horizon.posY += p->horizon.dirY * p->horizon.movespeed * 0.5;
    }
    if (p->fps.backward == 1)
    {
        if (moving_ok(p->map.tab[(int)(p->horizon.posY)]
        [(int)(p->horizon.posX - p->horizon.dirX * p->horizon.movespeed)]))
            p->horizon.posX -= p->horizon.dirX * p->horizon.movespeed * 0.5;
        if (moving_ok(p->map.tab[(int)(p->horizon.posY - p->horizon.dirY * p->horizon.movespeed)]
        [(int)(p->horizon.posX)]))
            p->horizon.posY -= p->horizon.dirY * p->horizon.movespeed * 0.5;
    }
    if (p->fps.left == 1)
    {
        if (moving_ok(p->map.tab[(int)(p->horizon.posY)]
        [(int)(p->horizon.posX - p->horizon.dirY * p->horizon.movespeed)]))
            p->horizon.posX += p->horizon.dirY * p->horizon.movespeed * 0.5;
        if (moving_ok(p->map.tab[(int)(p->horizon.posY + p->horizon.dirX * p->horizon.movespeed)]
        [(int)(p->horizon.posX)])) 
            p->horizon.posY += p->horizon.dirX * p->horizon.movespeed * 0.5;
    }
    if (p->fps.right == 1)
    {
        if (moving_ok(p->map.tab[(int)(p->horizon.posY)]
        [(int)(p->horizon.posX + p->horizon.dirY * p->horizon.movespeed)]))
            p->horizon.posX -= p->horizon.dirY * p->horizon.movespeed * 0.5;
        if (moving_ok(p->map.tab[(int)(p->horizon.posY - p->horizon.dirX * p->horizon.movespeed)]
        [(int)(p->horizon.posX)]))
            p->horizon.posY -= p->horizon.dirX * p->horizon.movespeed * 0.5;
    }
    rotate(p);
    return (0);
}