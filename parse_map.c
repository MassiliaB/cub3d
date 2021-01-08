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

int	ft_isview(char view, t_param *p)
{
    if (view == 'W')
    {
	p->person.view_nu = 8;
	return (1);
    }
    return (0);
}

int	get_tab(char *line, t_param *p)
{
    int x;

    x = 0;
    while (x < (p->map.mapX))
    {
	if(!(p->map.tab[p->map.mapY] = (int *)malloc(sizeof(int) * p->map.mapX)))
	    return (0);
	if (ft_isdigit(*line))
	    p->map.tab[p->map.mapY][x] = *line - '0'; 
	else if (ft_isview(*line, p))
	{
	    p->person.view = *line;
	    p->map.tab[p->map.mapY][x] = p->person.view_nu;
	}
	x++;
	line++;
    }
}

int	parse_map(t_param *p, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
	{
		get_elements(line + 2, p);
		return (1);
	}
	if (ft_isdigit(*line))
	{
		get_tab(line, p);
		p->map.mapY++;
		return (1);
	}
	if (*line == ' ')
		return (1);
	return (0);
}

void	count_lines(t_param *p, char *line, int fd)
{
    int size;
    int	ret;

    size = 0;
    ret = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
	if (ft_isdigit(*line))
	    size++;
	free(line);
    }
    if (ret == -1)
	print_error("Problem getting the lines\n");
    if (close(fd) == -1)
	print_error("FD closing error\n");
    if (!(p->map.tab = (int **)malloc(sizeof(int*) * (size))))
	    return ;
}

void	parse_no_error(t_param *p, int fd, char *path)
{
    int	ret;
    char	*line;

    ret = 0;
    line = NULL;
    p->map.mapY = 0;
    count_lines(p, line, fd);
    fd = open_cub(p, path);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
	p->map.mapX = ft_strlen2(line);
	if (!(parse_map(p, line)))
	{
	    print_error("Problem with the elements\n");
	    return ;
	}
	free(line);
    }
    if (ret == -1)
	print_error("Problem getting the lines\n");
    if (close(fd) == -1)
	print_error("FD closing error\n");
}

int	open_cub(t_param *p, char *path)
{
	int	fd;

	fd = 0;
	if (ft_strlen(path) < 4)
	    print_error("Need a cub file\n");
	if (!(ft_strstr(path, ".cub")))
	    print_error("Need a .cub file\n");
	else
	    if ((fd = open(path, O_RDONLY)) == -1)
		return (quit(p, "FD Error\n"));
	return (fd);
}
