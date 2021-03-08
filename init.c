/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:02:39 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 16:06:38 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void			paths(t_param *p)
{
	p->text.sp_addr = mlx_get_data_addr(p->img.sprite,
	&(p->img.bits_per_pixel_sp), &(p->img.line_length_sp), &(p->img.endian_sp));
	p->text.tex_height = 0;
	p->text.tex_width = 0;
	free(p->text.sprite_path);
	free(p->text.ea_path);
	free(p->text.we_path);
	free(p->text.so_path);
	free(p->text.no_path);
}

int				get_tex_path(t_param *p)
{
	if (!(p->img.no = mlx_xpm_file_to_image(p->vars.mlx_ptr, p->text.no_path,
	&p->text.no_width, &p->text.no_height)))
		return (quit(p, "Error :\nThis NO path doesn't exist.\n", NULL));
	p->text.no_addr = mlx_get_data_addr(p->img.no, &p->img.bits_per_pixel_no,
	&p->img.line_length_no, &p->img.endian_no);
	if (!(p->img.so = mlx_xpm_file_to_image(p->vars.mlx_ptr, p->text.so_path,
	&p->text.so_width, &p->text.so_height)))
		return (quit(p, "Error :\nThis SO path doesn't exist.\n", NULL));
	p->text.so_addr = mlx_get_data_addr(p->img.so, &(p->img.bits_per_pixel_so),
	&(p->img.line_length_so), &(p->img.endian_so));
	if (!(p->img.we = mlx_xpm_file_to_image(p->vars.mlx_ptr, p->text.we_path,
	&p->text.we_width, &p->text.we_height)))
		return (quit(p, "Error :\nThis WE path doesn't exist.\n", NULL));
	p->text.we_addr = mlx_get_data_addr(p->img.we, &(p->img.bits_per_pixel_we),
	&(p->img.line_length_we), &(p->img.endian_we));
	if (!(p->img.ea = mlx_xpm_file_to_image(p->vars.mlx_ptr, p->text.ea_path,
	&p->text.ea_width, &p->text.ea_height)))
		return (quit(p, "Error :\nThis EA path doesn't exist.\n", NULL));
	p->text.ea_addr = mlx_get_data_addr(p->img.ea, &(p->img.bits_per_pixel_ea),
	&(p->img.line_length_ea), &(p->img.endian_ea));
	if (!(p->img.sprite = mlx_xpm_file_to_image(p->vars.mlx_ptr,
	p->text.sprite_path, &p->text.sp_width, &p->text.sp_height)))
		return (quit(p, "Error :\nThis SPRITE path doesn't exist.\n", NULL));
	paths(p);
	return (0);
}

void			init_img(t_param *p)
{
	int i;

	i = 0;
	p->colors.wall = creat_trgb(0, 47, 95, 95);
	p->colors.floor = creat_trgb(1, p->colors.floor_r,
	p->colors.floor_g, p->colors.floor_b);
	p->colors.sky = creat_trgb(0, p->colors.sky_r,
	p->colors.sky_g, p->colors.sky_b);
	p->colors.sprite = creat_trgb(0, 119, 190, 1);
	p->sprite_ptr = get_sprites_pos(p, i);
}

void			init_tex(t_param *p)
{
	p->map.tab = NULL;
	p->vars.win_ptr = NULL;
	p->vars.mlx_ptr = NULL;
	p->img.sprite = NULL;
	p->sprite_ptr = NULL;
	p->sprite.sprite_order = 0;
	p->sprite.sp_dist = 0;
	p->img.so = NULL;
	p->img.no = NULL;
	p->img.ea = NULL;
	p->img.we = NULL;
	p->img.img = NULL;
	p->text.sprite_path = NULL;
	p->text.ea_path = NULL;
	p->text.we_path = NULL;
	p->text.so_path = NULL;
	p->text.no_path = NULL;
}

void			init_player(t_param *p)
{
	p->horizon.movespeed = 0.4;
	p->horizon.rotspeed = 0.05;
	p->touch = 0;
	p->sprite.num_sprites = 0;
	p->fps.rot_right = 0;
	p->fps.rot_left = 0;
	p->fps.forward = 0;
	p->fps.backward = 0;
	p->fps.left = 0;
	p->fps.right = 0;
	p->win_height = 0;
	p->win_width = 0;
	p->colors.floor_r = 0;
	p->colors.floor_g = 0;
	p->colors.floor_b = 0;
	p->colors.sky_g = 0;
	p->colors.sky_r = 0;
	p->colors.sky_b = 0;
	p->horizon.view = 0;
	p->map.nb_lines = 0;
	p->map.col_max = 0;
	p->map.mapx = 0;
	p->map.mapy = 0;
	init_tex(p);
}
