/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:57:16 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 12:59:09 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	bmp_make(t_param *p, int fd, int tmp)
{
	write(fd, "BM", 2);
	tmp = 54 + 4 * p->win_width * p->win_height;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	tmp = p->win_width;
	write(fd, &tmp, 4);
	tmp = p->win_height;
	write(fd, &tmp, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &p->img.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

int		save(t_param *p)
{
	int fd;
	int x;
	int y;
	int tmp;

	tmp = 0;
	if ((fd = open("./game.bmp", O_CREAT | O_RDWR, 0666)) == -1)
		return (quit(p, "Error :\nProblem creating the bmp fd.\n", NULL));
	bmp_make(p, fd, tmp);
	y = p->win_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < p->win_width)
		{
			write(fd, &p->img.addr[y * p->img.line_length + x * 4], 4);
			x++;
		}
		y--;
	}
	if (close(fd) == -1)
		return (quit(p, "Error :\nClosing the bmp FD failed.\n", NULL));
	return (quit(p, "Image saved !\n", NULL));
}
