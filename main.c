#include "inc/cub3d.h"

void		check_resolution(t_param *p)
{
	mlx_get_screen_size(p->vars.mlx_ptr, &p->get_screenX, &p->get_screenY);
	if (p->win_width > p->get_screenX)
		p->win_width = p->get_screenX;
	if (p->win_height > p->get_screenY)
		p->win_height = p->get_screenY;
}

int		main_loop(t_param *p)
{
	if (!(p->vars.mlx_ptr = mlx_init()))
		return (quit(p, "Error :\nCan't connect..\n", NULL));
	if (!(p->vars.win_ptr = mlx_new_window(p->vars.mlx_ptr, p->win_width, p->win_height, "cub3d")))
	    return (quit(p, "Error :\nMlx_new_window NULL.\n", NULL));
	if (!(p->img.img = mlx_new_image(p->vars.mlx_ptr, p->win_width, p->win_height)))
	    return (quit(p,"Error :\nMlx_new_image NULL.\n", NULL));
	if (!(p->img.addr = mlx_get_data_addr(p->img.img, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian))))
	    return (quit(p, "Error :\nMlx_get_data_add.\n", NULL));
//	printf("hello\n");
	check_resolution(p);
	get_tex_path(p);
	mlx_hook(p->vars.win_ptr, KEYPRESS, KEYPRESS_MASK, key_press, p);
	mlx_hook(p->vars.win_ptr, KEYRELEASE, KEYRELEASE_MASK, key_release, p);
	mlx_hook(p->vars.win_ptr, MOUSEPRESS, MOUSEPRESS_MASK, mlx_exit, p);
	mlx_loop_hook(p->vars.mlx_ptr, get_update, p);
	mlx_put_image_to_window(p->vars.mlx_ptr, p->vars.win_ptr, p->img.img, 0, 0);
	mlx_loop(p->vars.mlx_ptr);
	return(1);
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
