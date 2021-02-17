#include "../inc/cub3d.h"

int	set_camwe(char view, t_param *p)
{
	if (view == 'W')
	{
		p->horizon.dirX = 0;
		p->horizon.dirY = -1;
		p->horizon.planeX = p->horizon.dirY * tan(1.25 / 2);
		p->horizon.planeY = p->horizon.dirX * tan(1.25 / 2);
		return (1);
	}
	else if (view == 'E')
	{
		p->horizon.dirX = 0;
		p->horizon.dirY = 1;
		p->horizon.planeX = p->horizon.dirY * tan(1.25 / 2);
		p->horizon.planeY = -p->horizon.dirX * tan(1.25 / 2);
		return (1);
	}
	return (0);
}

int	set_camsn(char view, t_param *p)
{
	if (view == 'S')
	{
		p->horizon.dirX = 1;
		p->horizon.dirY = 0;
		p->horizon.planeX = -p->horizon.dirY * tan(1.25 / 2);
		p->horizon.planeY = -p->horizon.dirX * tan(1.25 / 2);
		return (1);
	}
	else if (view == 'N')
	{
		p->horizon.dirX = -1;
		p->horizon.dirY = 0;
		p->horizon.planeX = p->horizon.dirY * tan(1.25 / 2);
		p->horizon.planeY = -p->horizon.dirX * tan(1.25 / 2);
		return (1);
	}
	return (0);
}

int		ft_isview(char view, t_param *p)
{
	if (set_camwe(view, p))
		return (1);
	if (set_camsn(view, p))
		return (1);
    return (0);
}

int		is_there_num(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
	    if (ft_isdigit(line[i]))
			return (1);
		if (line[i] == ' ')
	    	i++;
		else
			return (0);	
	}
	return (0);
}