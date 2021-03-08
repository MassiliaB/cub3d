/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:45:21 by masboula          #+#    #+#             */
/*   Updated: 2021/02/25 14:32:32 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	sort(t_param *p, int i, int tmp)
{
	tmp = p->sprite.sp_dist[i];
	p->sprite.sp_dist[i] = p->sprite.sp_dist[i + 1];
	p->sprite.sp_dist[i + 1] = tmp;
	tmp = p->sprite.sprite_order[i];
	p->sprite.sprite_order[i] = p->sprite.sprite_order[i + 1];
	p->sprite.sprite_order[i + 1] = tmp;
}

void	sort_sprite(t_param *p)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < p->sprite.num_sprites)
	{
		p->sprite.sprite_order[i] = i;
		p->sprite.sp_dist[i] = ((p->horizon.posx - p->sprite_ptr[i].x)
		* (p->horizon.posx - p->sprite_ptr[i].x)
		+ (p->horizon.posy - p->sprite_ptr[i].y) *
		(p->horizon.posy - p->sprite_ptr[i].y));
		i++;
	}
	i = 0;
	while (i < (p->sprite.num_sprites - 1))
	{
		if (p->sprite.sp_dist[i] < p->sprite.sp_dist[i + 1])
		{
			sort(p, i, tmp);
			i = 0;
		}
		else
			i++;
	}
}

void	sprite_height(t_param *p)
{
	p->sprite.sprite_height = abs((int)(p->win_height
	/ p->sprite.transformy));
	p->draw.draw_starty = -p->sprite.sprite_height
	/ 2 + p->win_height / 2;
	if (p->draw.draw_starty < 0)
		p->draw.draw_starty = 0;
	p->draw.draw_endy = p->sprite.sprite_height
	/ 2 + p->win_height / 2;
	if (p->draw.draw_endy >= p->win_height)
		p->draw.draw_endy = p->win_height;
}

void	sprite_width(t_param *p)
{
	p->sprite.sprite_width = abs((int)(p->win_height / p->sprite.transformy));
	p->draw.draw_startx = -p->sprite.sprite_width
	/ 2 + p->sprite.sprite_screenx;
	if (p->draw.draw_startx < 0)
		p->draw.draw_startx = 0;
	p->draw.draw_endx = p->sprite.sprite_width / 2 + p->sprite.sprite_screenx;
	if (p->draw.draw_endx >= p->win_width)
		p->draw.draw_endx = p->win_width;
}

void	sprite_casting(t_param *p)
{
	int i;

	sort_sprite(p);
	i = 0;
	while (i < p->sprite.num_sprites)
	{
		p->sprite.spritex = p->sprite_ptr[p->sprite.sprite_order[i]].x
		- p->horizon.posx;
		p->sprite.spritey = p->sprite_ptr[p->sprite.sprite_order[i]].y
		- p->horizon.posy;
		p->sprite.invdet = 1.0 / (p->horizon.planex * p->horizon.diry
		- p->horizon.dirx * p->horizon.planey);
		p->sprite.transformx = p->sprite.invdet * (p->horizon.diry
		* p->sprite.spritex - p->horizon.dirx * p->sprite.spritey);
		p->sprite.transformy = p->sprite.invdet * (-p->horizon.planey
		* p->sprite.spritex + p->horizon.planex * p->sprite.spritey);
		p->sprite.sprite_screenx = (int)((p->win_width / 2)
		* (1 + p->sprite.transformx / p->sprite.transformy));
		sprite_height(p);
		sprite_width(p);
		put_sprite_on(p);
		i++;
	}
}
