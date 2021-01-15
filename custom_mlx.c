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

    x = -1;
    while (p->map.tab[y][++x])
		i = (int)ft_strlen(p->map.tab[x]);
    return (i);
}

void	my_cub_map(t_param *p)
{
    int	x;
    int	y;
    int tileY;
    int	tileX;
    int width;

    p->colors.wall = creat_trgb(0, 47, 95, 95);
    p->colors.floor = creat_trgb(0, p->colors.floor_r, p->colors.floor_g, p->colors.floor_b);
    p->colors.sky = creat_trgb(0, 191, 63, 63);

    width = p->win_width / (2 * p->map.line_max);
    y = 0;
    while (y < (p->map.mapY))
    {
		x = 0;
		p->map.mapX = ft_strlen2(p->map.tab[y]);
		init_player_map(p, x, y);
		while (x < (p->map.mapX))
		{
			tileY = y * width; 
			tileX = x * width;
			if (p->map.tab[y][x] == '1')
				display_cub_map(p, p->colors.wall, tileX, tileY, width);    
			else if (p->map.tab[y][x] == '0')
				display_cub_map(p, p->colors.floor, tileX, tileY, width);
			else if (ft_isview(p->map.tab[y][x], p))
				display_circle_map(p, tileX, tileY, width);
			else if (p->map.tab[y][x] == '2')
				display_cub_map(p, p->colors.sky, tileX, tileY, width);
			x++;
		}
		y++;
    }
}
