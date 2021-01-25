#include "cub3d.h"

int	 get_good_line(char *line, t_param *p, int x)
{
	if (ft_isdigit(*line) || *line == ' ')
		p->map.tab[p->map.mapY][x] = *line;
	else if (ft_isview(*line, p))
	{
	   	p->horizon.view = *line;
	   	p->map.tab[p->map.mapY][x] = *line;
		p->horizon.posX = x;
		p->horizon.posY = p->map.mapY;

	}
	if (!(ft_isdigit(*line)) && !(ft_isview(*line, p)) && !(*line == ' '))
		return (0);
	return (1);
}

int	get_tab(char *line, t_param *p)
{
    int x;
    int n;

    x = 0;
    n = 0;
    if (p->map.mapX >= p->map.col_max)
		p->map.col_max = p->map.mapX;
    else
		n = p->map.col_max - p->map.mapX;
    if (!(p->map.tab[p->map.mapY] = malloc(sizeof(char) * (p->map.mapX + n + 1))))
		return (0);
    while (x < (p->map.mapX))
    {
		if (!(get_good_line(line, p, x)))
	    	return (0);
		printf("[%c]",p->map.tab[p->map.mapY][x]);
		x++;
		line++;
    }
    while (x < p->map.col_max)
    {
		p->map.tab[p->map.mapY][x] = ' ';
		printf("[%c]",p->map.tab[p->map.mapY][x]);
		x++;
    }
    p->map.tab[p->map.mapY][x] = '\0';
	printf("\n");
    return (1);
}

int	parse_map(t_param *p, char *line)
{
	if (ft_strncmp(line, "R", 1) == 0)
	{
	    if (!(get_r(line + 1, p)))
			return (0);
	    return (1);
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
	    if (!(get_c(line + 1, p)))
			return (0);
	    return (1);
	}
	if (ft_strncmp(line, "F", 1) == 0)
	{
	    if (!(get_f(line + 1, p)))
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
	if (*line == ' ')
		return (1);
	return (0);
}
