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

void	display_circle_map(t_param *p, int x, int y)
{
  int	i;
  int j;
  double dist;

  p->fps.rad = 3;
  p->colors.person = creat_trgb(0, 255, 255, 255);
  j = 0;
  while (j <= 2 * p->fps.rad)
  {
    i = 0;
      while (i <= 2 * p->fps.rad)
      {
          dist = sqrt((i - p->fps.rad) * (i - p->fps.rad) + (j - p->fps.rad) * (j - p->fps.rad));
          if (dist > (p->fps.rad - 0.5) && dist < (p->fps.rad + 0.5))   
              my_mlx_pixel_put(p, i+x, j+y, p->colors.person);
          i++;
      }
      j++;
  }	
}

void	my_tiny_map(t_param *p)
{
    int	x;
    int	y;
    int tileY;
    int	tileX;
    int width;

    width = p->win_width / (2 * p->map.col_max);
    y = 0;
    while (y < p->map.mapY)
    {
		x = 0;
		p->map.mapX = ft_strlen2(p->map.tab[y]);
		while (x < p->map.mapX)
		{
			tileY = y * width; 
			tileX = x * width;
			if (p->map.tab[y][x] == '1')
				display_cub_map(p, p->colors.wall, tileX, tileY, width);
			else if (p->map.tab[y][x] == '0' || ft_isview(p->map.tab[y][x], p))
				display_cub_map(p, p->colors.floor, tileX, tileY, width);
			else if (p->map.tab[y][x] == '2')
				display_cub_map(p, p->colors.sprite, tileX, tileY, width);
			if (x == (int)p->horizon.posX && y == (int)p->horizon.posY)
				display_circle_map(p, tileX, tileY);
			x++;
		}
		y++;
    }
}