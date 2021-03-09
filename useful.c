/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:13:07 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 13:02:28 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int		word_check(char *str, char *comp)
{
	while (*comp)
	{
		if (*str != *comp)
			return (0);
		str++;
		comp++;
	}
	return (1);
}

int		creat_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_param *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length
	+ x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_len(int num)
{
	int size;

	size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

char	*ft_cleandup(char *str, char *dst)
{
	int i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
