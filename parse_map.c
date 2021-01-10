#include "cub3d.h"

int	get_elements(char *line, t_param *p)
{
	if (ft_isdigit(*line))
	{
		p->win_width = ft_atoi(line);
		while (ft_isdigit(*line))
		    line++;
		if (ft_isdigit(*++line))
		    p->win_height = ft_atoi(line);
		else
		{
			print_error("Coord Error\n");
			return (0);
		}
	}
	else
	{
		print_error("Coord Error\n");
		return (0);
	}
	return (1);
}

int		ft_isview(char view)
{
    if (view == 'W' || view == 'E' || view == 'S' || view == 'N')
		return (1);
    return (0);
}

int	 get_good_line(char *line, t_param *p, int x)
{
	if (p->map.mapY == 0 || x == 0 || x == (p->map.mapX - 1))
	{
		if (ft_isdigit(*line) != 1)
			return (0);
	}
	if (ft_isdigit(*line))
	   p->map.tab[p->map.mapY][x] = *line;
	else if (ft_isview(*line))
	{
	   p->person.view = *line;
	   p->map.tab[p->map.mapY][x] = *line;
	}
}

int	get_tab(char *line, t_param *p)
{
    int x;

    x = 0;
    while (x < (p->map.mapX))
    {
		if(!(p->map.tab[p->map.mapY] = (char *)malloc(sizeof(char) * p->map.mapX)))
	    	return (0);
		if (!(get_good_line(line, p, x)))
			return (0);
	//	printf("%c", p->map.tab[p->map.mapY][x]);
		x++;
		line++;

    }
	//printf("\n");
	return (1);
}

int		is_there_num(char *line)
{
	char *tmp;

	tmp = ft_strdup(line);
	while (*tmp)
	{
		if (ft_isdigit(*tmp))
			return (1);
		tmp++;
	}
	return (0);
}

int	parse_map(t_param *p, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
	{
		get_elements(line + 2, p);
		return (1);
	}
	if (is_there_num(line))
	{
		get_tab(line, p);
		p->map.mapY++;
		return (1);
	}
	return (0);
}

int		count_lines(t_param *p, char *line, int fd)
{
    int size;
    int	ret;

    size = 0;
    ret = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
		if (is_there_num(line))
	    	size++;
		free(line);
    }
    if (ret == -1)
		return (quit(p, "Problem getting the lines\n"));
    if (close(fd) == -1)
		return (quit(p, "Closing FD error\n"));
    if (!(p->map.tab = (char **)malloc(sizeof(char*) * (size))))
		return (quit(p, "Failed to malloc tab"));
}

int		parse_no_error(t_param *p, int fd, char *path)
{
    int		ret;
    char	*line;

    ret = 0;
    line = NULL;
    p->map.mapY = 0;
    if (!(count_lines(p, line, fd)))
		return (0);
    fd = open_cub(p, path);
    while ((ret = get_next_line(fd, &line)) > 0)
    { 
		p->map.mapX = ft_strlen2(line);
		if (!(parse_map(p, line)))
	    	return (quit(p, "Error with the map.\n"));
		free(line);
    }
	if (!(ft_isview(p->person.view)))
	    return (quit(p, "Error with the player on the map.\n"));
    if (ret == -1)
		return (quit(p, "Problem getting the lines\n"));
    if (close(fd) == -1)
		return (quit(p, "Closing FD error\n"));
	return (1);
}

int	open_cub(t_param *p, char *path)
{
	int	fd;

	fd = 0;
	if (ft_strlen(path) < 4)
	    return (quit(p, "Not a cub file\n"));
	if (!(ft_strstr(path, ".cub")))
	    return (quit(p, "Not a .cub file\n"));
	else if ((fd = open(path, O_RDONLY)) == -1)
		return (quit(p, "FD Error\n"));
	return (fd);
}
