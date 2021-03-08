/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:06:41 by masboula          #+#    #+#             */
/*   Updated: 2021/02/25 14:35:39 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_sprites_ptr	*get_sprites_pos(t_param *p, int i)
{
	t_sprites_ptr	*sprite_ptr;
	int				x;
	int				y;

	p->sprite.sprite_order = malloc(sizeof(int) * (p->sprite.num_sprites + 1));
	p->sprite.sp_dist = malloc(sizeof(double) * (p->sprite.num_sprites + 1));
	sprite_ptr = malloc(sizeof(t_sprites_ptr) * p->sprite.num_sprites);
	y = 0;
	while (y < p->map.mapy)
	{
		x = 0;
		p->map.mapx = ft_strlen2(p->map.tab[y]);
		while (x < p->map.mapx)
		{
			if (p->map.tab[y][x] == '2')
			{
				sprite_ptr[i].x = (double)x + 0.5;
				sprite_ptr[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	return (sprite_ptr);
}
