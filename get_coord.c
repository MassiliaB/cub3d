#include "cub3d.h"

int	get_r(char *line, t_param *p)
{
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
			return (quit(p, "Id 1Error.\n"));
	}
	else
		return (quit(p, "Id 2Error.\n"));
	return (1);
}

int	get_c(char *line, t_param *p)
{
	while (*line == ' ')
		line++;
    if (ft_isdigit(*line))
    {
		p->colors.sky_r = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if (ft_isdigit(*line))
			p->colors.sky_g = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if (ft_isdigit(*line))
			p->colors.sky_b = ft_atoi(line);
		else
			return (quit(p, "Id Error.\n"));
    }
    else
		return (quit(p, "Id Error.\n"));
    return (1);
}

int	get_f(char *line, t_param *p)
{
	while (*line == ' ')
		line++;
    if (ft_isdigit(*line))
    {		
		p->colors.floor_r = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if (ft_isdigit(*line))
			p->colors.floor_g = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == ',')
			line++;
		if (ft_isdigit(*line))
			p->colors.floor_b = ft_atoi(line);
		else
			return (quit(p, "Id Error.\n"));
    }
    else
		return (quit(p, "Id Error.\n"));
    return (1);
}
