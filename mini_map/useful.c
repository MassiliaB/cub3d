#include "../inc/cub3d.h"

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

int	ft_len(int num)
{
	int size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}