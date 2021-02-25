/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:48:32 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 16:14:00 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	choose_wall_dirwe(t_param *p)
{
	if (p->text.wall_dir == 'W')
	{
		p->text.img_addr = p->text.we_addr;
		p->text.tex_width = p->text.we_width;
		p->text.tex_height = p->text.we_height;
		p->text.ll = p->img.line_length_we;
		p->text.bpp = p->img.bits_per_pixel_we;
	}
	else if (p->text.wall_dir == 'E')
	{
		p->text.img_addr = p->text.ea_addr;
		p->text.tex_width = p->text.ea_width;
		p->text.tex_height = p->text.ea_height;
		p->text.ll = p->img.line_length_ea;
		p->text.bpp = p->img.bits_per_pixel_ea;
	}
}

void	choose_wall_dirns(t_param *p)
{
	p->text.step = 1.0 * p->text.tex_height / p->draw.line_height;
	p->text.tex_pos = (p->draw.draw_start - p->win_height
	/ 2 + p->draw.line_height / 2) * p->text.step;
	if (p->text.wall_dir == 'N')
	{
		p->text.img_addr = p->text.no_addr;
		p->text.tex_width = p->text.no_width;
		p->text.tex_height = p->text.no_height;
		p->text.ll = p->img.line_length_no;
		p->text.bpp = p->img.bits_per_pixel_no;
	}
	else if (p->text.wall_dir == 'S')
	{
		p->text.img_addr = p->text.so_addr;
		p->text.tex_width = p->text.so_width;
		p->text.tex_height = p->text.so_height;
		p->text.ll = p->img.line_length_so;
		p->text.bpp = p->img.bits_per_pixel_so;
	}
	else
		choose_wall_dirwe(p);
}

void	line_wall(t_param *p, int x)
{
	p->draw.line_height = (int)(p->win_height / p->horizon.perpwalldist);
	p->draw.draw_start = -p->draw.line_height / 2 + p->win_height / 2;
	if (p->draw.draw_start < 0)
		p->draw.draw_start = 0;
	p->draw.draw_end = p->draw.line_height / 2 + p->win_height / 2;
	if (p->draw.draw_end >= p->win_height)
		p->draw.draw_end = p->win_height - 1;
	wall_tex_value(p, x);
}

void	put_floorsky(t_param *p)
{
	int i;
	int j;

	i = 0;
	while (i < p->win_width)
	{
		j = 0;
		while (j < p->win_height / 2)
		{
			my_mlx_pixel_put(p, i, j, p->colors.sky);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < p->win_width)
	{
		j = p->win_height / 2;
		while (j < p->win_height)
		{
			my_mlx_pixel_put(p, i, j, p->colors.floor);
			j++;
		}
		i++;
	}
}
