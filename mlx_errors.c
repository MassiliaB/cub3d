#include "inc/cub3d.h"

int		parse_error(t_param *p)
{
	if ((ft_len(p->win_width) < 3 && ft_len(p->win_height) < 3)
	|| p->win_width > INT_MAX || p->win_height  > INT_MAX)
		return (quit(p, "Error :\nResolution is not adapted.\n", NULL));
	if (p->colors.sky_r > INT_MAX || p->colors.sky_r > 255 ||
	p->colors.sky_g > INT_MAX || p->colors.sky_g > 255 ||
	p->colors.sky_b > INT_MAX || p->colors.sky_b > 255 )
		return (quit(p, "Error :\nThe C colors are not set well.\n", NULL));
	if (p->colors.floor_r > INT_MAX || p->colors.floor_r > 255 ||
	p->colors.floor_g > INT_MAX || p->colors.floor_g > 255 ||
	p->colors.floor_b > INT_MAX || p->colors.floor_b > 255 )
		return (quit(p, "Error :\nThe F colors are not set well.\n", NULL));
	if (!(check_col(p)))
		return (quit(p, "Error :\nYou have to close the map only with '1'.\n", NULL));
    if (!p->text.no_path || !p->text.so_path || !p->text.we_path || !p->text.ea_path)
        return (quit(p, "Error :\nMissing to specify a texture.\n", NULL));
    if (!(ft_isview(p->horizon.view, p)))
	    return (quit(p, "Error :\nThere is no player in your map :(\n", NULL));
	return (1);
}

void		free_malloc(t_param *p, char *line)
{
	int i;

	i = 0;
	if (line != NULL)
	{	
		free(line);
        line = NULL;
	}
	if (p->map.tab != NULL)
	{
		while (p->map.tab[i])
		{
			free(p->map.tab[i]);
			i++;
		}
		free(p->map.tab);
        p->map.tab = NULL;
	}
	if (p->sprite_ptr != NULL)
		free(p->sprite_ptr);
	if (p->sprite.sprite_dist != 0)
		free(p->sprite.sprite_dist);
	if (p->sprite.sprite_order != 0)
		free(p->sprite.sprite_order);
	if (p->text.we_path != 0)
		free(p->text.we_path);
	if (p->text.ea_path != 0)
		free(p->text.we_path);
	if (p->text.no_path != 0)
		free(p->text.no_path);
	if (p->text.so_path != 0)
		free(p->text.so_path);
}

int		print_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (0);
}

int		quit(t_param *p, char *str, char *line)
{
	print_error(str);
	free_malloc(p, line);
	exit (0);
}

int	mlx_exit(t_param *p)
{
	quit(p, "Closing the window.\n", NULL);
	exit (0);
}