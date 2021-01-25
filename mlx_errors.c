#include "cub3d.h"

int		print_error(t_param *p, char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
/*	i = 0;
	if (p->map.tab)
	{while (p->map.tab[i])
	{
		free(p->map.tab[i]);
		i++;
	}
	free(p->map.tab);
	p->map.tab = NULL;
	}*/
	return (0);
}

int		quit(t_param *params, char *str)
{
	print_error(params, str);
	/*if (params->vars.win_ptr != 0)
	{
		mlx_clear_window(params->vars.mlx_ptr, params->vars.win_ptr);
		mlx_destroy_window(params->vars.mlx_ptr, params->vars.win_ptr);
	}*/
	exit (0);
}