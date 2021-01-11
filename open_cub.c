#include "cub3d.h"

int	ft_is_id(char *id)
{
    if (*id == 'R' || *id == 'F' || *id == 'C' || *id == 'S'|| (*id == 'N' && *++id == 'O') || (*id == 'S' && *++id == 'O') || (*id == 'W' && *++id == 'E') || (*id == 'E' && *++id == 'A'))
	return (1);
    return (0);
}

int		malloc_lines(t_param *p, char *line, int fd)
{
    int size;
    int	ret;

    size = 0;
    ret = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
	if (is_there_num(line) && (ft_is_id(line) == 0))
	    size++;
	free(line);
    }
    p->map.nb_lines = size;
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
    p->map.line_max = 0;
    if (!(malloc_lines(p, line, fd)))
	return (0);
    fd = open_cub(p, path);
    while ((ret = get_next_line(fd, &line)) > 0)
    { 
	    p->map.mapX = ft_strlen2(line);
	    if (!(parse_map(p, line)))
	    {
		free(line);
		return (quit(p, "Error with the map.\n"));
	    }
	    free(line);
    }
    if (!(check_col(p)))
	return (quit(p, "Error with the map.\n"));
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
