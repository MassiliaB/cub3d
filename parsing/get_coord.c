/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:47:57 by masboula          #+#    #+#             */
/*   Updated: 2021/02/23 16:49:14 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		get_r(char *line, t_param *p)
{
	if (p->win_width != 0 && p->win_height != 0)
		return (quit(p, "Error :\nYou have two R.\n", NULL));
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
	{
		p->win_width = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			p->win_height = ft_atoi(line);
		else
			return (quit(p, "Id Error.\n", line));
	}
	else
		return (quit(p, "Id Error.\n", line));
	return (1);
}

char	*check_order(char *line)
{
	while (*line == ' ')
		line++;
	if (*line == ',')
	{
		line++;
		while (*line == ' ')
			line++;
		if (*line == ',')
			return (NULL);
		else
			return (line);
	}
	return (NULL);
}

int		get_c(char *line, t_param *p)
{
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
	{
		p->colors.sky_r = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		if ((line = ft_cleandup(check_order(line), line)) == NULL)
			return (quit(p, "Error :\nThe C colors are not set well.\n", line));
		if (ft_isdigit(*line))
		{
			p->colors.sky_g = ft_atoi(line);
			while (ft_isdigit(*line))
				line++;
		}
		if ((line = ft_cleandup(check_order(line), line)) == NULL)
			return (quit(p, "Error :\nThe C colors are not set well.\n", line));
		if (ft_isdigit(*line))
			p->colors.sky_b = ft_atoi(line);
		else
			return (quit(p, "Id Error.\n", line));
	}
	else
		return (quit(p, "Id Error.\n", line));
	return (1);
}

int		get_f(char *line, t_param *p)
{
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
	{
		p->colors.floor_r = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		if ((line = ft_cleandup(check_order(line), line)) == NULL)
			return (quit(p, "Error :\nThe F colors are not set well.\n", line));
		if (ft_isdigit(*line))
		{
			p->colors.floor_g = ft_atoi(line);
			while (ft_isdigit(*line))
				line++;
		}
		if ((line = ft_cleandup(check_order(line), line)) == NULL)
			return (quit(p, "Error :\nThe F colors are not set well.\n", line));
		if (ft_isdigit(*line))
			p->colors.floor_b = ft_atoi(line);
		else
			return (quit(p, "Id Error.\n", line));
	}
	else
		return (quit(p, "Id Error.\n", line));
	return (1);
}
