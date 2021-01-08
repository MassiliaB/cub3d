#include "cub3d.h"

void    ft_init_horizon(t_param *p)
{
    int  pixels;
  /*  t_horizon hor;


    hor->posX = 22;
    hor->posY = 12;
    hor->dirX = -1;
    hor->dirY = 0;
    hor->planeX = 0;
    hor->planeY = 0.66;
    line->mapX = (int)hor->posX;
    line->mapY = (int)hor->posY;
    hor->deltaX = fabs(1 / hor->rayDirX);
    hor->deltaY = fabs(1 / hor->rayDirY);*/
    p->height = Height;
    p->width = Width;
	p->img.bits_per_pixel = 4;
    p->img.line_length = 1;
   p->img.endian = 0;
}

/*void    my_mlx_pixel_put(t_img *img, t_init *init, int color)
{
    char    *dst;
    t_horizon hor;
    t_map     line;
    int     x;
    int wall_hit;
    int wall_side;

    wall_hit = 0;
    x = 0;
    ft_init();
    while (x < Width)
    {
        hor.cameraX = 2 * x / (double)Width - 1;
        ft_init_horizon(init, &line, &hor);
        x++;
    }
    
}*/

/*void    my_mlx_image(int color, t_param *p)
{
    int y;
    int x;
    int pixel;
    char *dst;

    x = 0;
    y = 0;
    if (p->img.bits_per_pixel == 32)
        color = 0xABCDEF;
    dst = p->img.addr;
    while(y < p->height)
    {
        while(x < p->width)
        {
            pixel = (y * p->img.line_length) + (x * 4);
            dst[pixel + 0] = (color >> 24);
            x++;
        }
        y++;
    }
    

}

void		main_loop(t_param *p)
{
    int     color;

    color = creat_trgb(40, 135, 103, 22);

    p->img.img = mlx_new_image(p->vars.mlx_ptr, p->width, p->height);
	p->img.addr = mlx_get_data_addr(p->img.img, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian));
 //   my_mlx_pixel_put(&p->img, 5, 5, color);
 //   my_mlx_image(color, p);
    mlx_put_image_to_window(p->vars.mlx_ptr, p->vars.win_ptr, p->img.img, 530, 330);
//    mlx_destroy_image(p->vars.mlx_ptr, p->img.img);
//	mlx_loop_hook(p->vars.mlx_ptr, , p);
	mlx_loop(p->vars.mlx_ptr);
}*/



int main(void)
{
    t_param params;
    t_init  vars;
    int     color;

    color = creat_trgb(40, 135, 103, 22);

	if (!(vars.mlx_ptr = mlx_init()))
        return (print_error("Can't connect"));
    if (!(vars.win_ptr = mlx_new_window(vars.mlx_ptr, params.width, params.height, "cub3d")))
        return (quit(&params, "mlx_new_window NULL"));
  //  if (!(params.img.img = mlx_new_image(vars.mlx_ptr, params.width, params.height)))
    //    return (quit(&params,"mlx_new_image NULL"));
   // if (!(params.img.addr = mlx_get_data_addr(params.img.img, &(params.img.bits_per_pixel), &(params.img.line_length), &(params.img.endian))))
     //   return (quit(&params, "mlx_get_data_add Error"));
   // ft_init_horizon(&params);
    mlx_loop(vars.mlx_ptr);
//    main_loop(&params);
	return (0);
}

/*void    my_mlx_pixel_put(t_img *img, t_init *init, int color)
{   
    t_horizon hor;

    t_map     line;
        char    *dst;
    int x;
    int y;

    x = 0;
    while (x < Width)
    {
        ft_init_horizon(init, img, &line, &hor);
        hor.cameraX = 2 * x / (double)Width - 1;
        hor.rayDirX = hor.dirX + hor.planeX * hor.cameraX;
        hor.rayDirY = hor.dirY + hor.planeY * hor.cameraX;
        line.mapX = (int)hor.posX;
        line.mapY = (int)hor.posY;
        x++;
    }
}
/*  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = (color >> 24);

  if (hor.rayDirX < 0)
        {
            hor.stepX = -1;
            hor.sideDistX = (hor.posX - line.mapX) * hor.deltaDistX;
        }
        else
        {
            hor.stepX = 1;
            hor.sideDistX = (line.mapX + 1.0 - hor.posX) * hor.deltaDistX;
        }
        if (hor.rayDirY < 0)
        {
            hor.stepY = -1;
            hor.sideDistY = (hor.posY - line.mapY) * hor.deltaDistY;
        }
        else
        {
            hor.stepY = 1;
            hor.sideDistY = (line.mapY + 1.0 - hor.posY) * hor.deltaDistY;
        }

        while (wall_hit == 0)
        {
            if (hor.sideDistX < hor.sideDistY)
            {
                hor.sideDistX += hor.deltaDistX;
                line.mapX += hor.stepX;
                wall_side = 0;
            }
            else
            {
                hor.sideDistY += hor.deltaDistY;
                line.mapY += hor.stepY;
                wall_side = 1;
            }
            if (worldmap[line.mapX][line.mapY] > 0)
                wall_hit = 1;
        }
*/      
