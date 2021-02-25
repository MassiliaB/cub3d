/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:19:01 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 13:05:37 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		moving_ok(char moove)
{
	if (moove == '1' || moove == '2')
		return (0);
	return (1);
}

void	rotright(t_param *p)
{
	if (p->fps.rot_right == 1)
	{
		p->horizon.olddirx = p->horizon.dirx;
		p->horizon.dirx = p->horizon.dirx * cos(p->horizon.rotspeed)
		- p->horizon.diry * sin(p->horizon.rotspeed);
		p->horizon.diry = p->horizon.olddirx * sin(p->horizon.rotspeed)
		+ p->horizon.diry * cos(p->horizon.rotspeed);
		p->horizon.oldplanex = p->horizon.planex;
		p->horizon.planex = p->horizon.planex * cos(p->horizon.rotspeed)
		- p->horizon.planey * sin(p->horizon.rotspeed);
		p->horizon.planey = p->horizon.oldplanex * sin(p->horizon.rotspeed)
		+ p->horizon.planey * cos(p->horizon.rotspeed);
	}
}

void	rotate(t_param *p)
{
	if (p->fps.rot_left == 1)
	{
		p->horizon.olddirx = p->horizon.dirx;
		p->horizon.dirx = p->horizon.dirx * cos(-p->horizon.rotspeed)
		- p->horizon.diry * sin(-p->horizon.rotspeed);
		p->horizon.diry = p->horizon.olddirx * sin(-p->horizon.rotspeed)
		+ p->horizon.diry * cos(-p->horizon.rotspeed);
		p->horizon.oldplanex = p->horizon.planex;
		p->horizon.planex = p->horizon.planex * cos(-p->horizon.rotspeed)
		- p->horizon.planey * sin(-p->horizon.rotspeed);
		p->horizon.planey = p->horizon.oldplanex * sin(-p->horizon.rotspeed)
		+ p->horizon.planey * cos(-p->horizon.rotspeed);
	}
	rotright(p);
}

void	movelr(t_param *p)
{
	if (p->fps.left == 1)
	{
		if (moving_ok(p->map.tab[(int)p->horizon.posy]
		[(int)(p->horizon.posx - p->horizon.planex * p->horizon.movespeed)]))
			p->horizon.posx -= p->horizon.planex * p->horizon.movespeed;
		if (moving_ok(p->map.tab[(int)(p->horizon.posy - p->horizon.planey
		* p->horizon.movespeed)][(int)(p->horizon.posx)]))
			p->horizon.posy -= p->horizon.planey * p->horizon.movespeed;
	}
	if (p->fps.right == 1)
	{
		if (moving_ok(p->map.tab[(int)p->horizon.posy]
		[(int)(p->horizon.posx + p->horizon.planex * p->horizon.movespeed)]))
			p->horizon.posx += p->horizon.planex * p->horizon.movespeed;
		if (moving_ok(p->map.tab[(int)(p->horizon.posy + p->horizon.planey
		* p->horizon.movespeed)][(int)(p->horizon.posx)]))
			p->horizon.posy += p->horizon.planey * p->horizon.movespeed;
	}
}

void	move(t_param *p)
{
	if (p->fps.forward == 1)
	{
		if (moving_ok(p->map.tab[(int)p->horizon.posy]
		[(int)(p->horizon.posx + p->horizon.dirx * p->horizon.movespeed)]))
			p->horizon.posx += p->horizon.dirx * p->horizon.movespeed;
		if (moving_ok(p->map.tab[(int)(p->horizon.posy + p->horizon.diry
		* p->horizon.movespeed)][(int)(p->horizon.posx)]))
			p->horizon.posy += p->horizon.diry * p->horizon.movespeed;
	}
	if (p->fps.backward == 1)
	{
		if (moving_ok(p->map.tab[(int)p->horizon.posy]
		[(int)(p->horizon.posx - p->horizon.dirx * p->horizon.movespeed)]))
			p->horizon.posx -= p->horizon.dirx * p->horizon.movespeed;
		if (moving_ok(p->map.tab[(int)(p->horizon.posy - p->horizon.diry
		* p->horizon.movespeed)][(int)(p->horizon.posx)]))
			p->horizon.posy -= p->horizon.diry * p->horizon.movespeed;
	}
	movelr(p);
	rotate(p);
}
