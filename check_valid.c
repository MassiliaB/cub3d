#include "cub3d.h"

void	set_camwe(char view, t_param *p)
{
	if (view == 'W')
	{
		p->horizon.dirX = 0.0;
		p->horizon.dirY = -1;
		p->horizon.planeX = -0.66;
		p->horizon.planeY = 0.0;
	}
	else if (view == 'E')
	{
		p->horizon.dirX = 0.0;
		p->horizon.dirY = 1;
		p->horizon.planeX = 0.66;
		p->horizon.planeY = 0;
	}
}

void	set_camsn(char view, t_param *p)
{
	if (view == 'S')
	{
		p->horizon.dirX = 1;
		p->horizon.dirY = 0;
		p->horizon.planeX = 0;
		p->horizon.planeY = -0.66;
	}
	else if (view == 'N')
	{
		p->horizon.dirX = -1;
		p->horizon.dirY = 0.0;
		p->horizon.planeX = 0.0;
		p->horizon.planeY = 0.66;
	}		
}

int		ft_isview(char view, t_param *p)
{
    if (view == 'W')
	{
		set_camwe(view, p);
		return (1);
	}
	if (view == 'E')
	{
		set_camwe(view, p);
		return (1);
	}
	if (view == 'S')
	{
		set_camsn(view, p);
		return (1);
	}
	if (view == 'N')
	{		
		set_camsn(view, p);
		return (1);
	}
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