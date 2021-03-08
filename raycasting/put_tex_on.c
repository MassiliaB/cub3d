/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tex_on.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:37:04 by masboula          #+#    #+#             */
/*   Updated: 2021/03/03 12:52:58 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_color(t_param *p)
{
	int color;
	int index;

	color = 0;
	p->sprite.d = (p->sprite.y) * 256 - p->win_height * 128
	+ p->sprite.sprite_height * 128;
	p->sprite.texy = ((p->sprite.d * p->text.sp_height) /
	p->sprite.sprite_height) / 256;
	index = abs(p->sprite.texy) * p->img.line_length_sp +
	abs(p->sprite.texx) * (p->img.bits_per_pixel_sp / 8);
	ft_memcpy(&color, &p->text.sp_addr[index], 4);
	if (color && 0x00FFFFFF != 0)
		my_mlx_pixel_put(p, p->sprite.stripe, p->sprite.y, color);
}

void	put_sprite_on(t_param *p)
{
	p->sprite.stripe = p->draw.draw_startx;
	while (p->sprite.stripe < p->draw.draw_endx)
	{
		p->sprite.texx = (int)(256 * (p->sprite.stripe -
		(-p->sprite.sprite_width / 2 + p->sprite.sprite_screenx))
		* p->text.sp_width / p->sprite.sprite_width) / 256;
		if (p->sprite.transformy > 0 && p->sprite.stripe > 0
		&& p->sprite.stripe < p->win_width && p->sprite.transformy
		< p->sprite.buff[p->sprite.stripe])
		{
			p->sprite.y = p->draw.draw_starty;
			while (p->sprite.y < p->draw.draw_endy)
			{
				put_color(p);
				p->sprite.y++;
			}
		}
		p->sprite.stripe++;
	}
}

void	put_tex_on(t_param *p, int x)
{
	int		y;
	int		color;
	char	*color2;

	y = p->draw.draw_start;
	while (y < p->draw.draw_end)
	{
		p->text.texy = (int)p->text.tex_pos & (p->text.tex_height - 1);
		p->text.tex_pos += p->text.step;
		color2 = p->text.img_addr + (abs(p->text.texy) * p->text.ll
		+ abs(p->text.texx) * (p->text.bpp / 8));
		color = *(unsigned int *)color2;
		if (p->horizon.side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(p, x, y, color);
		y++;
	}
	p->sprite.buff[x] = p->horizon.perpwalldist;
}

void	tex_side(t_param *p)
{
	if (p->horizon.side == 0)
	{
		if (p->horizon.raydirx > 0)
			p->text.wall_dir = 'E';
		else
			p->text.wall_dir = 'W';
	}
	if (p->horizon.side == 1)
	{
		if (p->horizon.raydiry < 0)
			p->text.wall_dir = 'N';
		else
			p->text.wall_dir = 'S';
	}
}

void	wall_tex_value(t_param *p, int x)
{
	p->text.tex_num = p->map.tab[p->horizon.currentposy]
	[p->horizon.currentposx] - 1;
	if (p->horizon.side == 0)
		p->text.wallx = p->horizon.posy + p->horizon.perpwalldist
		* p->horizon.raydiry;
	else
		p->text.wallx = p->horizon.posx + p->horizon.perpwalldist
		* p->horizon.raydirx;
	p->text.wallx -= floor(p->text.wallx);
	p->text.texx = (int)(p->text.wallx * (double)p->text.tex_width);
	tex_side(p);
	choose_wall_dirns(p);
	put_tex_on(p, x);
}
