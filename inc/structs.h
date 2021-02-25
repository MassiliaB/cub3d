/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:23:39 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 16:27:32 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct		s_texture
{
	char	*no_path;
	char	*no_addr;
	char	*so_path;
	char	*so_addr;
	char	*we_path;
	char	*we_addr;
	char	*ea_path;
	char	*ea_addr;
	char	*sprite_path;
	char	*sp_addr;
	int		tex_width;
	int		tex_height;
	int		tex_num;
	double	wallx;
	int		texx;
	char	*tex_addr;
	char	*img_addr;
	double	step;
	double	tex_pos;
	int		texy;
	char	wall_dir;
	int		no_width;
	int		no_height;
	int		so_width;
	int		so_height;
	int		we_width;
	int		we_height;
	int		ea_width;
	int		ea_height;
	int		sp_width;
	int		sp_height;
	int		bpp;
	int		ll;

}					t_texture;

typedef struct		s_sprites_ptr
{
	double	x;
	double	y;
	int		texture;
}					t_sprites_ptr;

typedef struct		s_sprites
{

	int		x;
	int		y;
	int		d;
	int		tex;
	double	*buff;
	double	*sp_dist;
	int		*sprite_order;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		sprite_screenx;
	int		sprite_height;
	int		sprite_width;
	int		stripe;
	int		texx;
	int		texy;
	int		num_sprites;
}					t_sprites;

typedef struct		s_player
{
	int		rad;
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
	double	rot_angle;
	int		x;
	int		y;
}					t_player;

typedef struct		s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}					t_mlx;

typedef struct		s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*no;
	int		bits_per_pixel_no;
	int		line_length_no;
	int		endian_no;
	void	*so;
	int		bits_per_pixel_so;
	int		line_length_so;
	int		endian_so;
	void	*we;
	int		bits_per_pixel_we;
	int		line_length_we;
	int		endian_we;
	void	*ea;
	int		bits_per_pixel_ea;
	int		line_length_ea;
	int		endian_ea;
	void	*sprite;
	int		bits_per_pixel_sp;
	int		line_length_sp;
	int		endian_sp;
}					t_img;

typedef struct		s_map
{
	int		mapx;
	int		mapy;
	char	**tab;
	int		nb_lines;
	int		col_max;
	int		width;
	int		tiley;
	int		tilex;
}					t_map;

typedef struct		s_colors
{
	int		floor;
	int		sky;
	int		wall;
	int		person;
	int		sprite;
	int		sky_r;
	int		sky_g;
	int		sky_b;
	int		floor_r;
	int		floor_g;
	int		floor_b;

}					t_colors;

typedef struct		s_horizon
{
	double	deltax;
	double	deltay;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	char	view;
	int		side;
	int		hit;
	double	movespeed;
	double	rotspeed;
	double	olddirx;
	double	oldplanex;
	int		currentposx;
	int		currentposy;
}					t_horizon;

typedef struct		s_draw
{
	int		draw_start;
	int		line_height;
	int		draw_end;
	int		draw_starty;
	int		draw_startx;
	int		draw_endy;
	int		draw_endx;
}					t_draw;

typedef struct		s_param
{
	t_mlx			vars;
	t_img			img;
	t_map			map;
	t_sprites_ptr	*sprite_ptr;
	t_sprites		sprite;
	t_player		fps;
	t_horizon		horizon;
	t_colors		colors;
	t_draw			draw;
	t_texture		text;
	int				win_width;
	int				win_height;
	int				touch;
	int				save;
	int				get_screenx;
	int				get_screeny;
}					t_param;

#endif
