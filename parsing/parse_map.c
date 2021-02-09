#include "../inc/cub3d.h"

int	 get_good_line(char *line, t_param *p, int x)
{
	if (ft_isdigit(*line) || *line == ' ')
	{
		p->map.tab[p->map.mapY][x] = *line;
		if (*line == '2')
			p->sprite.num_sprites += 1;
	}
	else if (ft_isview(*line, p))
	{
		if (p->horizon.view != 0)
			return (quit(p, "Error :\nTwo players on the map.\n"));
	   	p->horizon.view = *line;
	   	p->map.tab[p->map.mapY][x] = '0';
		p->horizon.posX = x + 0.5;
		p->horizon.posY = p->map.mapY + 0.5;

	}
	if (!(ft_isdigit(*line)) && !(ft_isview(*line, p))
	&& !(*line == ' '))
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
//		printf("[%c]", p->map.tab[p->map.mapY][x]);
		x++;
		line++;
    }
	x--;
    while (++x < p->map.col_max)
	{	
		p->map.tab[p->map.mapY][x] = ' ';
//		printf("[%c]", p->map.tab[p->map.mapY][x]);
		}
//printf("\n");
    p->map.tab[p->map.mapY][x] = '\0';
    return (1);
}

int	parse_map_tex(t_param *p, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
        if (!(get_no(line + 2, p)))
			return (0);
	if (ft_strncmp(line, "SO", 2) == 0)
	    if (!(get_so(line + 2, p)))
			return (0);
	if (ft_strncmp(line, "WE", 2) == 0)
	    if (!(get_we(line + 2, p)))
			return (0);
	if (ft_strncmp(line, "EA", 2) == 0)
	    if (!(get_ea(line + 2, p)))
			return (0);
    if (ft_strncmp(line, "NO", 2) != 0 && ft_strncmp(line, "SO", 2) != 0
    && ft_strncmp(line, "WE", 2) != 0 && ft_strncmp(line, "EA", 2) != 0)
        return (0);
	return (1);
}

int	parse_map_coord(t_param *p, char *line)
{
	if (ft_strncmp(line, "R", 1) == 0)
	    if (!(get_r(line + 1, p)))
			return (0);
	if (ft_strncmp(line, "C", 1) == 0)
	    if (!(get_c(line + 1, p)))
			return (0);
	if (ft_strncmp(line, "F", 1) == 0)
	    if (!(get_f(line + 1, p)))
			return (0);
	if (ft_strncmp(line, "S ", 2) == 0)
	    if (!(get_sprite(line + 2, p)))
			return (0);
	if (ft_strncmp(line, "R", 1) != 0 && ft_strncmp(line, "C", 1) != 0
    && ft_strncmp(line, "F", 1) != 0 && ft_strncmp(line, "S ", 2) != 0)
        return (0);
	return (1);
}

int	parse_map(t_param *p, char *line)
{
	if (parse_map_tex(p, line) && p->map.mapY == 0)
		return (1);
	if (parse_map_coord(p, line) && p->map.mapY == 0)
		return (1);
	if (*(line + 1) == '\0' && p->map.mapY == 0)
		return (1);
	if (is_there_num(line))
	{
	    if (!(get_tab(line, p)))
			return (0);
	    p->map.mapY++;
	    return (1);
	}
	return (0);
}