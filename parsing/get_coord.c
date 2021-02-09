#include "../inc/cub3d.h"

int	get_r(char *line, t_param *p)
{
	if (p->win_width != 0 && p->win_height != 0)
		return (quit(p, "Error :\nYou have two R.\n"));
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
	{
		p->win_width = ft_atoi(line);
	    while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
	    if (ft_isdigit(*line))
			p->win_height = ft_atoi(line);
		else
			return (quit(p, "Id Error.\n"));
	}
	else
		return (quit(p, "Id Error.\n"));
	return (1);
}

char	*check_order(char *line)
{
	while (*line == ' ')
		line++;
	if (*line == ',')
	{
		line++;;
		while (*line == ' ')
			line++;
		if (*line == ',')
			return (NULL);
		else
			return (line);
	}
	return (NULL);
}

int	get_c(char *line, t_param *p)
{
	if (p->colors.sky_r != 0 && p->colors.sky_g != 0 && p->colors.sky_b != 0)
		return (quit(p, "Error :\nYou have two C.\n"));
	while (*line == ' ')
		line++;
    if (ft_isdigit(*line))
    {
		p->colors.sky_r = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		if ((line = ft_strdup(check_order(line))) == NULL)
			return (quit(p, "Error :\nThe C colors are not set well.\n"));
		if (ft_isdigit(*line))
		{
			p->colors.sky_g = ft_atoi(line);
			while (ft_isdigit(*line))
				line++;
		}
		if ((line = ft_strdup(check_order(line))) == NULL)
			return (quit(p, "Error :\nThe C colors are not set well.\n"));
		if (ft_isdigit(*line))
			p->colors.sky_b = ft_atoi(line);
		else
			return (quit(p, "Id1 Error.\n"));
    }
    else
		return (quit(p, "Id Error.\n"));
    return (1);
}

int	get_f(char *line, t_param *p)
{
	if (p->colors.floor_r != 0 && p->colors.floor_g != 0 && p->colors.floor_b != 0)
		return (quit(p, "Error :\nYou have two F.\n"));
	while (*line == ' ')
		line++;
    if (ft_isdigit(*line))
    {				
		p->colors.floor_r = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		if ((line = ft_strdup(check_order(line))) == NULL)
			return (quit(p, "Error :\nThe F colors are not set well.\n"));
		if (ft_isdigit(*line))
		{
			p->colors.floor_g = ft_atoi(line);
			while (ft_isdigit(*line))
				line++;
		}
		if ((line = ft_strdup(check_order(line))) == NULL)
			return (quit(p, "Error :\nThe F colors are not set well.\n"));
		if (ft_isdigit(*line))
			p->colors.floor_b = ft_atoi(line);
		else
			return (quit(p, "Id Error.\n"));
    }
    else
		return (quit(p, "Id Error.\n"));
    return (1);
}
