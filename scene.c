#include "cub3d.h"

void    stepY(t_param *p)
{
    if (p->horizon.rayDirY < 0)
    {
        p->horizon.stepY = -1;
        p->horizon.sideDistY = (p->horizon.posY - p->horizon.currentposY) * p->horizon.deltaDistY;
    }
    else
    {
        p->horizon.stepY = 1;
        p->horizon.sideDistY = (p->horizon.currentposY + 1.0 - p->horizon.posY) * p->horizon.deltaDistY;
    }
}

void    stepX(t_param *p, int x)
{
    p->horizon.cameraX = 2 * x / (double)p->win_width - 1;
    p->horizon.rayDirX = p->horizon.dirX + p->horizon.planeX * p->horizon.cameraX;
    p->horizon.rayDirY = p->horizon.dirY + p->horizon.planeY * p->horizon.cameraX;
    p->horizon.currentposX = p->horizon.posX;
    p->horizon.currentposY = p->horizon.posY;
    if (p->horizon.rayDirY == 0)
        p->horizon.deltaDistX = 0;
    else if (p->horizon.rayDirX == 0)
        p->horizon.deltaDistX = 1;
    else
        p->horizon.deltaDistX = fabs(1 / (p->horizon.rayDirX));
    if (p->horizon.rayDirX == 0)
        p->horizon.deltaDistY = 0;
    else if (p->horizon.rayDirY == 0)
        p->horizon.deltaDistY = 1;
    else
        p->horizon.deltaDistY = fabs(1 / (p->horizon.rayDirX));
    p->horizon.hit = 0;
    if (p->horizon.rayDirX < 0)
    {
        p->horizon.stepX = -1;
        p->horizon.sideDistX = (p->horizon.posX - p->horizon.currentposX) * p->horizon.deltaDistX;
    }
    else
    {
        p->horizon.stepX = 1;
        p->horizon.sideDistX = (p->horizon.currentposX + 1.0 - p->horizon.posX) * p->horizon.deltaDistX;
    }
    stepY(p);
}
        
void    ft_is_wall(t_param *p)
{
    while (p->horizon.hit == 0)
    {
        if (p->horizon.sideDistX < p->horizon.sideDistY)
        {
            p->horizon.sideDistX += p->horizon.deltaDistX;
            p->horizon.currentposX += p->horizon.stepX;
            p->horizon.side = 0;
        }
        else
        {
            p->horizon.sideDistY += p->horizon.deltaDistY;
            p->horizon.currentposY += p->horizon.stepY;
            p->horizon.side = 1;
        }
        if (p->map.tab[p->horizon.currentposY][p->horizon.currentposX] > 0)
            p->horizon.hit = 1;
    }
}

void    wall_dist(t_param *p)
{
    if (p->horizon.side == 0)
		p->horizon.perpwalldist = (p->horizon.currentposX - p->horizon.posX +
        (1 - p->horizon.stepX) / 2) / p->horizon.rayDirX;
	else
		p->horizon.perpwalldist = (p->horizon.currentposY - p->horizon.posY +
		(1 - p->horizon.stepY) / 2) / p->horizon.rayDirY;
}

void    init_rotTime(t_param *p)
{
    p->horizon.oldtime = p->horizon.time;
    //p->horizon.time = ?
    p->horizon.frameTime = (p->horizon.time -  p->horizon.oldtime) / 1000.0;
     //draw
    p->horizon.movespeed =  p->horizon.frameTime * 5.0;
    p->horizon.rotspeed =  p->horizon.frameTime * 3.0;
    //read key
}