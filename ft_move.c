#include "cub3d.h"

int moving_ok(char pos)
{
    if (pos == '1' || pos == '2')
        return (0);
    return (1);
}

void    rotate(t_param *p)
{
    if (p->fps.rotright == 1)
    {
        p->horizon.oldDirX = p->horizon.dirX;
        p->horizon.dirX = p->horizon.dirX * cos(-(p->horizon.rotspeed)) - p->horizon.dirY * sin(-(p->horizon.rotspeed));
        p->horizon.dirY = p->horizon.oldDirX * sin(-(p->horizon.rotspeed)) + p->horizon.dirY * cos(-(p->horizon.rotspeed));
        p->horizon.oldPlaneX = p->horizon.planeX;
        p->horizon.planeX = p->horizon.planeX * cos(-(p->horizon.rotspeed)) - p->horizon.planeY * sin(-(p->horizon.rotspeed));
        p->horizon.planeY = p->horizon.oldPlaneX * sin(-(p->horizon.rotspeed)) + p->horizon.planeY * cos(-(p->horizon.rotspeed));        
    }
    if (p->fps.rotleft == 1)
    {
        p->horizon.oldDirX = p->horizon.dirX;
        p->horizon.dirX = p->horizon.dirX * cos(p->horizon.rotspeed) - p->horizon.dirY * sin(p->horizon.rotspeed);
        p->horizon.dirY = p->horizon.oldDirX * sin(p->horizon.rotspeed) + p->horizon.dirY * cos(p->horizon.rotspeed);
        p->horizon.oldPlaneX = p->horizon.planeX;
        p->horizon.planeX = p->horizon.planeX * cos(p->horizon.rotspeed) - p->horizon.planeY * sin(p->horizon.rotspeed);
        p->horizon.planeY = p->horizon.oldPlaneX * sin(p->horizon.rotspeed) + p->horizon.planeY * cos(p->horizon.rotspeed);        
    }
    
}

int    move(t_param *p)
{
    if (p->fps.forward == 1)
    {
        if (moving_ok(p->map.tab[(int)(p->horizon.posY)][(int)(p->horizon.posX + p->horizon.dirX * p->horizon.movespeed)]))
            p->horizon.posX += p->horizon.dirX * p->horizon.movespeed;
        if (moving_ok(p->map.tab[(int)(p->horizon.posY + p->horizon.dirY * p->horizon.movespeed)][(int)(p->horizon.posX)])) 
            p->horizon.posY += p->horizon.dirY * p->horizon.movespeed;
    }
    if (p->fps.backward == 1)
    {
        if (moving_ok(p->map.tab[(int)(p->horizon.posY)][(int)(p->horizon.posX - p->horizon.dirX * p->horizon.movespeed)]))
            p->horizon.posX -= p->horizon.dirX * p->horizon.movespeed;
        if (moving_ok(p->map.tab[(int)(p->horizon.posY - p->horizon.dirY * p->horizon.movespeed)][(int)(p->horizon.posX)]))
            p->horizon.posY -= p->horizon.dirY * p->horizon.movespeed;
    }
    if (p->fps.left == 1)
    {
        if (moving_ok(p->map.tab[(int)(p->horizon.posY)][(int)(p->horizon.posX - p->horizon.dirY * p->horizon.movespeed)]))
            p->horizon.posX += p->horizon.dirY * p->horizon.movespeed;
        if (moving_ok(p->map.tab[(int)(p->horizon.posY + p->horizon.dirX * p->horizon.movespeed)][(int)(p->horizon.posX)])) 
            p->horizon.posY += p->horizon.dirX * p->horizon.movespeed;
    }
    if (p->fps.right == 1)
    {
        if (moving_ok(p->map.tab[(int)(p->horizon.posY)][(int)(p->horizon.posX + p->horizon.dirY * p->horizon.movespeed)]))
            p->horizon.posX -= p->horizon.dirY * p->horizon.movespeed;
        if (moving_ok(p->map.tab[(int)(p->horizon.posY - p->horizon.dirX * p->horizon.movespeed)][(int)(p->horizon.posX)]))
            p->horizon.posY -= p->horizon.dirX * p->horizon.movespeed;
    }
    rotate(p);
    return (0);
}