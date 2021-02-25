/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:11:00 by masboula          #+#    #+#             */
/*   Updated: 2021/02/25 14:05:17 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	check_resolution(t_param *p)
{
	mlx_get_screen_size(p->vars.mlx_ptr, &p->get_screenx,
	&p->get_screeny);
	if (p->win_width > p->get_screenx)
		p->win_width = p->get_screenx;
	if (p->win_height > p->get_screeny)
		p->win_height = p->get_screeny;
}

int		main_loop(t_param *p)
{
	if (!(p->vars.mlx_ptr = mlx_init()))
		return (quit(p, "Error :\nCan't connect..\n", NULL));
	if (!(p->vars.win_ptr = mlx_new_window(p->vars.mlx_ptr,
	p->win_width, p->win_height, "cub3d")))
		return (quit(p, "Error :\nMlx_new_window NULL.\n", NULL));
	check_resolution(p);
	get_tex_path(p);
	mlx_hook(p->vars.win_ptr, KEYPRESS, (1L << 0), key_press, p);
	mlx_hook(p->vars.win_ptr, KEYRELEASE, (1L << 1), key_release, p);
	mlx_hook(p->vars.win_ptr, MOUSEPRESS, (1L << 17), mlx_exit, p);
	mlx_loop_hook(p->vars.mlx_ptr, get_update, p);
	mlx_loop(p->vars.mlx_ptr);
	return (1);
}

int		main(int ac, char **av)
{
	t_param	params;
	int		fd;
	char	*path;

	path = av[1];
	params.save = 0;
	if ((ac < 2 && ac > 3) || (ac == 3 && !word_check(av[2], "--save")))
		return (print_error("Error :\nInvalid arguments.\n"));
	if ((fd = open_cub(&params, path)) == -1)
		return (0);
	if (ac == 3 && ft_strstr(av[2], "--save"))
		params.save = 1;
	init_player(&params);
	if (!(parse_cub(&params, fd, path)))
		return (0);
	init_img(&params);
	main_loop(&params);
	return (0);
}
