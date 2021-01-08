#include "cub3d.h"

int		print_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (0);
}

int		quit(t_param *params, char *str)
{
	print_error(str);
	mlx_destroy_image(params->vars.mlx_ptr, params->img.img);
	return (0);
}