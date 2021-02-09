#include "inc/cub3d.h"

void		check_resolution(t_param *p)
{
	mlx_get_screen_size(p->vars.mlx_ptr, &p->get_screenX, &p->get_screenY);
	if (p->win_width > p->get_screenX)
		p->win_width = p->get_screenX;
	if (p->win_height > p->get_screenY)
		p->win_height = p->get_screenY;
}

int		parse_error(t_param *p)
{
	if ((ft_len(p->win_width) < 3 && ft_len(p->win_height) < 3)
	|| p->win_width > INT_MAX || p->win_height  > INT_MAX)
		return (quit(p, "Error :\nResolution is not adapted.\n"));
	if (p->colors.sky_r > INT_MAX || p->colors.sky_r > 255 ||
	p->colors.sky_g > INT_MAX || p->colors.sky_g > 255 ||
	p->colors.sky_b > INT_MAX || p->colors.sky_b > 255 )
		return (quit(p, "Error :\nThe C colors are not set well.\n"));
	if (p->colors.floor_r > INT_MAX || p->colors.floor_r > 255 ||
	p->colors.floor_g > INT_MAX || p->colors.floor_g > 255 ||
	p->colors.floor_b > INT_MAX || p->colors.floor_b > 255 )
		return (quit(p, "Error :\nThe F colors are not set well.\n"));
	if (!(check_col(p)))
		return (quit(p, "Error :\nYou have to close the map only with '1'.\n"));
    if (!p->text.no_path || !p->text.so_path || !p->text.we_path || !p->text.ea_path)
        return (quit(p, "Error :\nMissing to specify a texture.\n"));
    if (!(ft_isview(p->horizon.view, p)))
	    return (quit(p, "Error :\nThere is no player in your map :(\n"));
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
	print_error(str);
	exit (0);
}

int	mlx_exit(t_param *p)
{
	print_error("Closing the window.\n");
	exit (0);
}