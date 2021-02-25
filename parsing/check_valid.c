/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:47:09 by masboula          #+#    #+#             */
/*   Updated: 2021/02/23 16:47:46 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	set_camwe(char view, t_param *p)
{
	if (view == 'S')
	{
		p->horizon.dirx = 0;
		p->horizon.diry = 1;
		p->horizon.planex = -p->horizon.diry * tan(1.25 / 2);
		p->horizon.planey = -p->horizon.dirx * tan(1.25 / 2);
		return (1);
	}
	else if (view == 'N')
	{
		p->horizon.dirx = 0;
		p->horizon.diry = -1;
		p->horizon.planex = -p->horizon.diry * tan(1.25 / 2);
		p->horizon.planey = p->horizon.dirx * tan(1.25 / 2);
		return (1);
	}
	return (0);
}

int	set_camsn(char view, t_param *p)
{
	if (view == 'W')
	{
		p->horizon.dirx = -1;
		p->horizon.diry = 0;
		p->horizon.planex = -p->horizon.diry * tan(1.25 / 2);
		p->horizon.planey = p->horizon.dirx * tan(1.25 / 2);
		return (1);
	}
	else if (view == 'E')
	{
		p->horizon.dirx = 1;
		p->horizon.diry = 0;
		p->horizon.planex = -p->horizon.diry * tan(1.25 / 2);
		p->horizon.planey = p->horizon.dirx * tan(1.25 / 2);
		return (1);
	}
	return (0);
}

int	ft_isview(char view, t_param *p)
{
	if (set_camwe(view, p))
		return (1);
	if (set_camsn(view, p))
		return (1);
	return (0);
}

int	is_there_num(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			return (1);
		if (line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (0);
}
