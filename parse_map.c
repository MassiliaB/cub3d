#include "cub3d.h"

int	 get_good_line(char *line, t_param *p, int x)
{
	if (ft_isdigit(*line) || *line == ' ')
	   p->map.tab[p->map.mapY][x] = *line;
	else if (ft_isview(*line))
	{
	//printf("wsh\n");
	   p->person.view = *line;
	   p->map.tab[p->map.mapY][x] = *line;
	}
	if (!(ft_isdigit(*line)) && !(ft_isview(*line)) && !(*line == ' '))
	    return (0);
	return (1);
}

int	get_tab(char *line, t_param *p)
{
    int x;

    x = 0;
    if(!(p->map.tab[p->map.mapY] = malloc(sizeof(char) * (p->map.mapX + 1))))
	return (0);
    while (x < (p->map.mapX))
    {
	if (!(get_good_line(line, p, x)))
	    return (0);
	x++;
	line++;
    }
    if (p->map.mapX > p->map.line_max)
	 p->map.line_max = p->map.mapX;
    else
    {
	while (x < p->map.line_max)
	{
	    p->map.tab[p->map.mapY][x] = ' ';
	    x++;
	}
    }
    p->map.tab[p->map.mapY][x] = '\0';
    return (1);
}


int	parse_map(t_param *p, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
	{
	    if (!(get_r(line + 2, p)))
		return (0);
	    return (1);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
	    if (!(get_c(line + 2, p)))
		return (0);
	    return (1);
	}
	if (ft_strncmp(line, "F ", 2) == 0)
	{
	    if (!(get_f(line + 2, p)))
		return (0);
	    return (1);
	}
	if (is_there_num(line))
	{
	    if (!(get_tab(line, p)))
		return (0);
	    p->map.mapY++;
	    return (1);
	}
	if (*line = ' ')
	   return (1);
	return (0);
}

