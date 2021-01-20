#include "cub3d.h"

int		main_loop(t_param *p)
{
	if (!(p->vars.mlx_ptr = mlx_init()))
	    return (print_error("Can't connect"));
	if (!(p->vars.win_ptr = mlx_new_window(p->vars.mlx_ptr, p->win_width, p->win_height, "cub3d")))
	    return (quit(p, "mlx_new_window NULL"));
	if (!(p->img.img = mlx_new_image(p->vars.mlx_ptr, p->win_width, p->win_height)))
	    return (quit(p,"mlx_new_image NULL"));
	if (!(p->img.addr = mlx_get_data_addr(p->img.img, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian))))
	    return (quit(p, "mlx_get_data_add Error"));
	put_floorsky(p);
	update_scene(p);
	mlx_hook(p->vars.win_ptr, KEYPRESS, KEYPRESS_MASK, key_press, p);
	mlx_hook(p->vars.win_ptr, KEYRELEASE, KEYRELEASE_MASK, key_release, p);
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

	if (ac < 2)
	    return (print_error("Wrong number of arguments.\nNeed one .cub file"));
	path = av[1];
	if ((fd = open_cub(&params, path)) == -1)
	    return (0);
	init_player(&params);
	if (!(parse_no_error(&params, fd, path)))
	    return (0);
	ft_init_img(&params);
	main_loop(&params);
	return (0);
}
