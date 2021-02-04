#include "cub3d.h"

int		open_parse_err(t_param *p)
{
	if (!(check_col(p)))
		return (quit(p, "Error :\nProblem with the map.\n"));
    if (!p->text.no_path || !p->text.so_path || !p->text.we_path || !p->text.ea_path)
        return (quit(p, "Error :\nMissing a texture.\n"));
    if (!(ft_isview(p->horizon.view, p)))
	    return (quit(p, "Error with the player on the map.\n"));
	return (1);
}

int		print_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (0);
}

int		quit(t_param *p, char *str)
{
	(void)p;
	print_error(str);
	/*if (params->vars.win_ptr != 0)
	{
		mlx_clear_window(params->vars.mlx_ptr, params->vars.win_ptr);
		mlx_destroy_window(params->vars.mlx_ptr, params->vars.win_ptr);
	}*/
	exit (0);
}