#include "cub3d.h"

int		creat_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void            my_mlx_pixel_put(t_param *data, int x, int y, int color)
{
	char    *dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	display_cub_map(t_param *p, int color, int x, int y, int width)
{
    int i;
    int j;

    j = y + width;
    while (j >= y)
    {
	i = x + width;
	while (i >=x)
	{
	    my_mlx_pixel_put(p, i, j, color);
	    i--;
	}
	j--;
    }
}

int	count_mapX(t_param *p, int y)
{
    int x;
    int i;
    int size;

    x = 0;
    i = y;
    while (p->map.tab[i])
	i++;
    while (x < i)
	x++;
    return (x);
}

void	my_cub_map(t_param *p)
{
    int	x;
    int	y;
    int tileY;
    int	tileX;

    p->colors.wall = creat_trgb(40, 47, 95, 95);
    p->colors.floor = creat_trgb(40, 165, 89, 89);
    p->colors.sky = creat_trgb(40, 0, 224, 224);

    y = 0;
    while (y < (p->map.mapY))
    {
	x = 0;
	p->map.mapX = count_mapX(p, y); 
printf("mapX [%d]\n", p->map.mapX);
	while (x < (p->map.mapX))
	{
	    tileY = y * p->img.bits_per_pixel; 
	    tileX = x * p->img.bits_per_pixel; 
	    if (p->map.tab[y][x] == 1)
		display_cub_map(p, p->colors.wall, tileX, tileY, p->img.bits_per_pixel);    
	    else if (p->map.tab[y][x] == 0)
		display_cub_map(p, p->colors.floor, tileX, tileY, p->img.bits_per_pixel);
	    x++;
	}
	y++;
    }
}
