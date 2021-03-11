/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:00:58 by masboula          #+#    #+#             */
/*   Updated: 2021/03/11 19:45:01 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	free_struct(t_param *p)
{
	if (p->sprite_ptr)
		free(p->sprite_ptr);
	if (p->sprite.sp_dist)
		free(p->sprite.sp_dist);
	if (p->sprite.sprite_order)
		free(p->sprite.sprite_order);
	if (p->text.ea_path)
		free(p->text.ea_path);
	if (p->text.we_path)
		free(p->text.we_path);
	if (p->text.no_path)
		free(p->text.no_path);
	if (p->text.so_path)
		free(p->text.so_path);
	if (p->text.sprite_path)
		free(p->text.sprite_path);
}

void	free_tabs(t_param *p, char *line)
{
	int i;

	i = 0;
	if (p->map.tab != NULL)
	{
		while (i < p->map.mapy)
		{
			free(p->map.tab[i]);
			i++;
		}
		free(p->map.tab);
	}
	if (line != NULL)
		free(line);
	free_struct(p);
}

int		print_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (0);
}

int		quit(t_param *p, char *str, char *line)
{
	print_error(str);
	free_tabs(p, line);
	if (p->img.ea)
		mlx_destroy_image(p->vars.mlx_ptr, p->img.ea);
	if (p->img.we)	
		mlx_destroy_image(p->vars.mlx_ptr, p->img.we);
	if (p->img.no)
		mlx_destroy_image(p->vars.mlx_ptr, p->img.no);
	if (p->img.so)
		mlx_destroy_image(p->vars.mlx_ptr, p->img.so);
	if (p->img.sprite)
		mlx_destroy_image(p->vars.mlx_ptr, p->img.sprite);
	if (p->save == 1)
		mlx_destroy_image(p->vars.mlx_ptr, p->img.img);
	if (p->vars.win_ptr)
		mlx_destroy_window(p->vars.mlx_ptr, p->vars.win_ptr);
	if (p->vars.mlx_ptr)
	{
		mlx_destroy_display(p->vars.mlx_ptr);
		free(p->vars.mlx_ptr);
	}
	exit(0);
}

int		mlx_exit(t_param *p)
{
	quit(p, "Closing the window.\n", NULL);
	exit(0);
}
