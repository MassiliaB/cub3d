#include "cub3d.h"

void	ft_init_img(t_param *p)
{
	p->img.bits_per_pixel = 32;
	p->img.line_length = 1;
	p->img.endian = 1;
}


int		main_loop(t_param *p)
{
	ft_init_img(p);
	if (!(p->vars.mlx_ptr = mlx_init()))
		return (print_error("Can't connect"));
	if (!(p->vars.win_ptr = mlx_new_window(p->vars.mlx_ptr, p->win_width, p->win_height, "cub3d")))
		return (quit(p, "mlx_new_window NULL"));
	if (!(p->img.img = mlx_new_image(p->vars.mlx_ptr, p->win_width, p->win_height)))
		return (quit(p,"mlx_new_image NULL"));
	if (!(p->img.addr = mlx_get_data_addr(p->img.img, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian))))
		return (quit(p, "mlx_get_data_add Error"));
	my_cub_map(p);
	mlx_put_image_to_window(p->vars.mlx_ptr, p->vars.win_ptr, p->img.img, 0, 0);
	mlx_loop(p->vars.mlx_ptr);
	return(0);
}

int		main(int ac, char **av)
{
	t_param	params;
	int		fd;
	char	*path;

	if (ac < 2)
		return (print_error("No enough args\nNeed a .cub file"));
	path = av[1];
	fd = open_cub(&params, path);
	parse_no_error(&params, fd, path);
	main_loop(&params);
	return (0);
}
