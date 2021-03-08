/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:40:08 by masboula          #+#    #+#             */
/*   Updated: 2021/03/03 12:51:54 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	display_cub_map(t_param *p, int color, int x, int y)
{
	int i;
	int j;

	j = y + p->map.width;
	while (j >= y)
	{
		i = x + p->map.width;
		while (i >= x)
		{
			my_mlx_pixel_put(p, i, j, color);
			i--;
		}
		j--;
	}
}

int		count_mapx(t_param *p, int y)
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
	int		i;
	int		j;
	double	dist;

	p->fps.rad = p->map.width / 2.2;
	p->colors.person = creat_trgb(0, 0, 0, 0);
	j = 0;
	while (j <= 2 * p->fps.rad)
	{
		i = 0;
		while (i <= 2 * p->fps.rad)
		{
			dist = sqrt((i - p->fps.rad) * (i - p->fps.rad)
			+ (j - p->fps.rad) * (j - p->fps.rad));
			if (dist > (p->fps.rad - 1) && dist < (p->fps.rad + 1))
				my_mlx_pixel_put(p, i + x, j + y, p->colors.person);
			i++;
		}
		j++;
	}
}

void	my_tiny_map(t_param *p)
{
	int	x;
	int	y;

	p->map.width = p->win_height / (p->map.col_max * 3);
	y = -1;
	while (++y < p->map.mapy)
	{
		x = -1;
		p->map.mapx = ft_strlen2(p->map.tab[y]);
		while (++x < p->map.mapx)
		{
			p->map.tiley = y * p->map.width;
			p->map.tilex = x * p->map.width;
			if (p->map.tab[y][x] == '1')
				display_cub_map(p, p->colors.wall, p->map.tilex, p->map.tiley);
			else if (p->map.tab[y][x] == '0')
				display_cub_map(p, p->colors.floor, p->map.tilex, p->map.tiley);
			else if (p->map.tab[y][x] == '2')
				display_cub_map(p, p->colors.sprite, p->map.tilex,
				p->map.tiley);
			if (x == (int)p->horizon.posx && y == (int)p->horizon.posy)
				display_circle_map(p, p->map.tilex, p->map.tiley);
		}
	}
}
