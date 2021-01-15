#include "cub3d.h"

/*void    ft_init_personizon(t_param *p)
{

    p->person.posX = 22;
    p->person.posY = 12;
    p->person.dirX = -1;
    p->person.dirY = 0;
    p->person.planeX = 0;
    p->person.planeY = 0.66;
    p->person.time = 0;
    p->person.oldtime = 0;    

    p->person.deltaX = fabs(1 / p->person.rayDirX);
    p->person.deltaY = fabs(1 / p->person.rayDirY);
}
*/

void    ft_stepy(t_param *p)
{
    if (p->person.rayDirY < 0)
    {
        p->person.stepY = -1;
        p->person.sideDistY = (p->person.posY - p->map.mapY) * p->person.deltaDistY;
    }
    else
    {
        p->person.stepY = 1;
        p->person.sideDistY = (p->map.mapY + 1.0 - p->person.posY) * p->person.deltaDistY;
    }

}

void    ft_steps(t_param *p, int x)
{
    p->person.cameraX = 2 * x / (double)p->win_width - 1;
    p->person.rayDirX = p->person.dirX + p->person.planeX * p->person.cameraX;
    p->person.rayDirY = p->person.dirY + p->person.planeY * p->person.cameraX;
    p->map.mapX = (int)p->person.posX;
    p->map.mapY = (int)p->person.posY;
    p->person.deltaDistX = sqrt(1 + (p->person.rayDirY * p->person.rayDirY) / (p->person.rayDirX * p->person.rayDirX));
    p->person.deltaDistY = sqrt(1 + (p->person.rayDirX * p->person.rayDirX) / (p->person.rayDirY * p->person.rayDirY));
    p->person.hit = 0;
    if (p->person.rayDirX < 0)
    {
        p->person.stepX = -1;
        p->person.sideDistX = (p->person.posX - p->map.mapX) * p->person.deltaDistX;
    }
    else
    {
        p->person.stepX = 1;
        p->person.sideDistX = (p->map.mapX + 1.0 - p->person.posX) * p->person.deltaDistX;
    }
    ft_stepy(p);
}
        
void    ft_is_wall(t_param *p)
{
    while (p->person.hit == 0)
    {
        if (p->person.sideDistX < p->person.sideDistY)
        {
            p->person.sideDistX += p->person.deltaDistX;
            p->map.mapX += p->person.stepX;
            p->person.side = 0;
        }
        else
        {
            p->person.sideDistY += p->person.deltaDistY;
            p->map.mapY += p->person.stepY;
            p->person.side = 1;
        }
        if (p->map.tab[p->map.mapX][p->map.mapY] > 0)
            p->person.hit = 1;
    }
}

void    ft_is_wall_side(t_param *p)
{
    if (p->person.side == 0)
		p->person.perpwalldist = (p->person.mapX - p->person.posX +
				(1 - p->person.stepX) / 2) / p->person.raydirX;
	else
		mlx->ray.perpwalldist = (mlx->ray.mapy - mlx->posy +
			(1 - mlx->ray.stepy) / 2) / mlx->ray.raydiry;
	mlx->zbuffer[x] = mlx->ray.perpwalldist;
}
/*void    ft_init_raycast(t_param *p)
{
    p->fps.x = x / (p->win_width * p->win_height) - 0.5;
    p->fps.angle = math.atan2(x, p->fps.focalength);
    p->fps.ray = p->map.tab
    p->fps.x = 14.7;
    p->fps.y = 5.09;
    p->fps.rot_angle = 0.0;
    p->fps.fov = M_PI / 4.0;
    p->fps.dist_max = 16.0;
    p->fps.move_speed = 5.0;
}
*/
