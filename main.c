#include "cub3d.h"

int		main_loop(t_param *p)
{
	if (!(p->vars.mlx_ptr = mlx_init()))
		return (quit(p, "Error : Can't connect..\n"));
	if (!(p->vars.win_ptr = mlx_new_window(p->vars.mlx_ptr, p->win_width, p->win_height, "cub3d")))
	    return (quit(p, "Error : mlx_new_window NULL.\n"));
	if (!(p->img.img = mlx_new_image(p->vars.mlx_ptr, p->win_width, p->win_height)))
	    return (quit(p,"Error : mlx_new_image NULL.\n"));
	if (!(p->img.addr = mlx_get_data_addr(p->img.img, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian))))
	    return (quit(p, "mlx_get_data_add Error.\n"));
 //   init_rotTime(p);
   my_cub_map(p);
//	mlx_hook(p->vars.win_ptr, KEYPRESS, KEYPRESS_MASK, key_press, p);
//	mlx_hook(p->vars.win_ptr, KEYRELEASE, KEYRELEASE_MASK, key_release, p);
//mlx_loop_hook(p->vars.mlx_ptr, get_update, p);
	mlx_loop(p->vars.mlx_ptr);
	return(1);
}

int		main(int ac, char **av)
{
	t_param	params;
	int		fd;
	char	*path;


	if (ac < 2 && ac > 3)
	    return (print_error(&params, "Invalid number of arguments.\n"));
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
