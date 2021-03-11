/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:00:58 by masboula          #+#    #+#             */
/*   Updated: 2021/03/11 19:49:21 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	parse_error(t_param *p)
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
