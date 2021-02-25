/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:23:07 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 16:12:49 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	stepy(t_param *p)
{
	if (p->horizon.raydiry < 0)
	{
		p->horizon.stepy = -1;
		p->horizon.sidedisty = (p->horizon.posy - p->horizon.currentposy)
		* p->horizon.deltadisty;
	}
	else
	{
		p->horizon.stepy = 1;
		p->horizon.sidedisty = (p->horizon.currentposy + 1.0 - p->horizon.posy)
		* p->horizon.deltadisty;
	}
}

void	ray_dirx(t_param *p)
{
	if (p->horizon.raydirx < 0)
	{
		p->horizon.stepx = -1;
		p->horizon.sidedistx = (p->horizon.posx - p->horizon.currentposx)
		* p->horizon.deltadistx;
	}
	else
	{
		p->horizon.stepx = 1;
		p->horizon.sidedistx = (p->horizon.currentposx + 1.0 - p->horizon.posx)
		* p->horizon.deltadistx;
	}
}

void	stepx(t_param *p, int x)
{
	p->horizon.camerax = 2 * x / (double)p->win_width - 1;
	p->horizon.raydirx = p->horizon.dirx + p->horizon.planex
	* p->horizon.camerax;
	p->horizon.raydiry = p->horizon.diry + p->horizon.planey
	* p->horizon.camerax;
	p->horizon.currentposx = (int)p->horizon.posx;
	p->horizon.currentposy = (int)p->horizon.posy;
	if (p->horizon.raydiry == 0)
		p->horizon.deltadistx = 0;
	else
		p->horizon.deltadistx = (p->horizon.raydirx == 0) ?
		1 : fabs(1 / (p->horizon.raydirx));
	if (p->horizon.raydirx == 0)
		p->horizon.deltadisty = 0;
	else
		p->horizon.deltadisty = (p->horizon.raydiry == 0) ?
		1 : fabs(1 / (p->horizon.raydiry));
	p->horizon.hit = 0;
	ray_dirx(p);
	stepy(p);
}

void	ft_is_wall(t_param *p)
{
	while (p->horizon.hit == 0)
	{
		if (p->horizon.sidedistx < p->horizon.sidedisty)
		{
			p->horizon.sidedistx += p->horizon.deltadistx;
			p->horizon.currentposx += p->horizon.stepx;
			p->horizon.side = 0;
		}
		else if (p->horizon.sidedistx > p->horizon.sidedisty)
		{
			p->horizon.sidedisty += p->horizon.deltadisty;
			p->horizon.currentposy += p->horizon.stepy;
			p->horizon.side = 1;
		}
		if (p->map.tab[p->horizon.currentposy][p->horizon.currentposx] == '1')
			p->horizon.hit = 1;
	}
}

void	wall_dist(t_param *p)
{
	if (p->horizon.side == 0)
		p->horizon.perpwalldist = (p->horizon.currentposx - p->horizon.posx +
		(1 - p->horizon.stepx) / 2) / p->horizon.raydirx;
	else
		p->horizon.perpwalldist = (p->horizon.currentposy - p->horizon.posy +
		(1 - p->horizon.stepy) / 2) / p->horizon.raydiry;
}
