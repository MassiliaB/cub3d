/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:53:40 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 16:10:54 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		get_good_line(char *line, t_param *p, int x)
{
	if (ft_isdigit(*line) || *line == ' ')
	{
		p->map.tab[p->map.mapy][x] = *line;
		if (*line == '2')
			p->sprite.num_sprites++;
	}
	else if (ft_isview(*line, p))
	{
		if (p->horizon.view != 0)
			return (quit(p, "Error :\nTwo players on the map.\n", line));
		p->horizon.view = *line;
		p->map.tab[p->map.mapy][x] = '0';
		p->horizon.posx = x + 0.5;
		p->horizon.posy = p->map.mapy + 0.5;
	}
	if (!(ft_isdigit(*line)) && !(ft_isview(*line, p))
	&& !(*line == ' '))
		return (0);
	return (1);
}

int		get_tab(char *line, t_param *p)
{
	int x;
	int n;

	x = 0;
	n = 0;
	if (p->map.mapx >= p->map.col_max)
		p->map.col_max = p->map.mapx;
	else
		n = p->map.col_max - p->map.mapx;
	if (!(p->map.tab[p->map.mapy] = malloc(sizeof(char)
	* (p->map.mapx + n + 1))))
		return (0);
	while (x < (p->map.mapx))
	{
		if (!(get_good_line(line + x, p, x)))
			return (0);
		x++;
	}
	line += x;
	x--;
	while (++x < p->map.col_max)
		p->map.tab[p->map.mapy][x] = ' ';
	p->map.tab[p->map.mapy][x] = '\0';
	return (1);
}

int		parse_map_tex(t_param *p, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		get_no(line + 2, p);
	if (ft_strncmp(line, "SO", 2) == 0)
		get_so(line + 2, p);
	if (ft_strncmp(line, "WE", 2) == 0)
		get_we(line + 2, p);
	if (ft_strncmp(line, "EA", 2) == 0)
		get_ea(line + 2, p);
	if (ft_strncmp(line, "NO", 2) != 0 && ft_strncmp(line, "SO", 2) != 0
		&& ft_strncmp(line, "WE", 2) != 0 && ft_strncmp(line, "EA", 2) != 0)
		return (0);
	return (1);
}

int		parse_map_coord(t_param *p, char *line)
{
	if (ft_strncmp(line, "R", 1) == 0)
		get_r(line + 1, p);
	if (ft_strncmp(line, "C", 1) == 0)
	{
		if (p->colors.sky_r != 0 && p->colors.sky_g != 0
		&& p->colors.sky_b != 0)
			return (quit(p, "Error :\nYou have two C.\n", NULL));
		get_c(line + 1, p);
	}
	if (ft_strncmp(line, "F", 1) == 0)
	{
		if (p->colors.floor_r != 0 && p->colors.floor_g
		!= 0 && p->colors.floor_b != 0)
			return (quit(p, "Error :\nYou have two F.\n", NULL));
		get_f(line + 1, p);
	}
	if (ft_strncmp(line, "S ", 2) == 0)
		get_sprite(line + 2, p);
	if (ft_strncmp(line, "R", 1) != 0 && ft_strncmp(line, "C", 1) != 0
			&& ft_strncmp(line, "F", 1) != 0 && ft_strncmp(line, "S ", 2) != 0)
		return (0);
	return (1);
}

int		parse_map(t_param *p, char *line)
{
	if (parse_map_tex(p, line) && !p->map.mapy)
		return (1);
	if (parse_map_coord(p, line) && !p->map.mapy)
		return (1);
	if (*line == '\0' && !p->map.mapy)
		return (1);
	if (is_there_num(line))
	{
		if (!(get_tab(line, p)))
			return (0);
		p->map.mapy++;
		return (1);
	}
	if (*line == '\0' && p->map.mapy == p->map.nb_lines)
		return (1);
	return (0);
}
