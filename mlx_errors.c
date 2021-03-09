/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:00:58 by masboula          #+#    #+#             */
/*   Updated: 2021/03/03 12:50:46 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int		parse_error(t_param *p)
{
	if ((ft_len(p->win_width) < 3 && ft_len(p->win_height) < 3)
	|| p->win_width > INT_MAX || p->win_height > INT_MAX)
		return (quit(p, "Error :\nResolution is not adapted.\n", NULL));
	if (p->colors.sky_r > INT_MAX || p->colors.sky_r > 255 ||
	p->colors.sky_g > INT_MAX || p->colors.sky_g > 255 ||
	p->colors.sky_b > INT_MAX || p->colors.sky_b > 255)
		return (quit(p, "Error :\nThe C colors are not set well.\n", NULL));
	if (p->colors.floor_r > INT_MAX || p->colors.floor_r > 255 ||
	p->colors.floor_g > INT_MAX || p->colors.floor_g > 255 ||
	p->colors.floor_b > INT_MAX || p->colors.floor_b > 255)
		return (quit(p, "Error :\nThe F colors are not set well.\n", NULL));
	if (!(check_col(p)))
		return (quit(p, "Error :\nYou have to close only with '1'.\n", NULL));
	if (!p->text.no_path || !p->text.so_path || !p->text.we_path
	|| !p->text.ea_path)
		return (quit(p, "Error :\nMissing to specify a texture.\n", NULL));
	if (!(ft_isview(p->horizon.view, p)))
		return (quit(p, "Error :\nThere is no player in your map :(\n", NULL));
	return (1);
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
