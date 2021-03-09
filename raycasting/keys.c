/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:22:48 by masboula          #+#    #+#             */
/*   Updated: 2021/03/03 12:52:18 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	update_scene(t_param *p)
{
	int x;

	x = 0;
	put_floorsky(p);
	p->sprite.buff = (double *)malloc(sizeof(double) * p->win_width + 1);
	while (x < p->win_width)
	{
		stepx(p, x);
		ft_is_wall(p);
		wall_dist(p);
		line_wall(p, x);
		x++;
	}
	sprite_casting(p);
	free(p->sprite.buff);
	if (p->save == 1)
		save(p);
	return (0);
}

int	get_update(t_param *p)
{
	if (!(p->img.img = mlx_new_image(p->vars.mlx_ptr,
	p->win_width, p->win_height)))
		return (quit(p, "Error :\nMlx_new_image NULL.\n", NULL));
	if (!(p->img.addr = mlx_get_data_addr(p->img.img, &(p->img.bits_per_pixel),
	&(p->img.line_length), &(p->img.endian))))
		return (quit(p, "Error :\nMlx_get_data_add.\n", NULL));
	move(p);
	update_scene(p);
	if (p->touch % 2 == 1)
		my_tiny_map(p);
	mlx_put_image_to_window(p->vars.mlx_ptr, p->vars.win_ptr, p->img.img, 0, 0);
	mlx_destroy_image(p->vars.mlx_ptr, p->img.img);
	return (0);
}

int	key_release(int keycode, t_param *p)
{
	if (keycode == GO_FORWARD)
		p->fps.forward = 0;
	if (keycode == GO_DOWN)
		p->fps.backward = 0;
	if (keycode == GO_LEFT)
		p->fps.left = 0;
	if (keycode == GO_RIGHT)
		p->fps.right = 0;
	if (keycode == ROT_LEFT)
		p->fps.rot_left = 0;
	if (keycode == ROT_RIGHT)
		p->fps.rot_right = 0;
	return (0);
}

int	key_press(int keycode, t_param *p)
{
	if (keycode == DISP_MAP)
		p->touch = (p->touch + 1) % 2;
	if (keycode == ESC)
		mlx_exit(p);
	if (keycode == GO_FORWARD)
		p->fps.forward = 1;
	if (keycode == GO_DOWN)
		p->fps.backward = 1;
	if (keycode == GO_LEFT)
		p->fps.left = 1;
	if (keycode == GO_RIGHT)
		p->fps.right = 1;
	if (keycode == ROT_LEFT)
		p->fps.rot_left = 1;
	if (keycode == ROT_RIGHT)
		p->fps.rot_right = 1;
	return (0);
}
