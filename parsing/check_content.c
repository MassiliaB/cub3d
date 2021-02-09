# include "cub3d.h"

int	check_line(t_param *p, int y, int x)
{
    if ((p->map.tab[y][x] >= '0' && p->map.tab[y][x] <= '2')
	|| ft_isview(p->map.tab[y][x], p) || p->map.tab[y][x] == ' ')
    {
		if (y == 0 || x == 0 || y == (p->map.nb_lines - 1))
	    	if (p->map.tab[y][x] != ' ' && p->map.tab[y][x] != '1')
				return (0);
		if (p->map.tab[y][x] == ' ')
	    	if ((p->map.tab[y][x + 1] != '1' && p->map.tab[y][x + 1] != ' '
			&& p->map.tab[y][x + 1] != '\0') || (x != 0 && (p->map.tab[y][x - 1] != ' '
			&& p->map.tab[y][x - 1] != '1')))
				return (0);
		if (p->map.tab[y][x] == '0' || p->map.tab[y][x] == '2')
			if (p->map.tab[y][x + 1] == ' ' || p->map.tab[y][x - 1] == ' ')
				return (0);
		return (1);
   }
   return (0);
}

int	check_col(t_param *p)
{
    int x;
    int y;

    y = 0;
    while (y < p->map.mapY)
    {
		x = 0;
		while (p->map.tab[y][x])
		{
			if (!check_line(p, y, x))
				return (0);
			if ((p->map.tab[y][x] == '0' || p->map.tab[y][x] == '2') &&
			(p->map.tab[y - 1][x - 1] == ' ' || p->map.tab[y - 1][x + 1] == ' '
			|| p->map.tab[y + 1][x - 1] == ' ' || p->map.tab[y + 1][x + 1] == ' '
			|| p->map.tab[y - 1][x] == ' ' || p->map.tab[y - 1][x] == ' '
			|| p->map.tab[y + 1][x] == ' '|| p->map.tab[y + 1][x] == ' '))
				return (0);
			x++;
		}
		y++;
    }
    return (1);
}
