#include "cub3d.h"

int	ft_is_id(char *id)
{
    if (*id == 'R' || *id == 'F' || *id == 'C'
    || *id == 'S'|| (*id == 'N' && *++id == 'O')
    || (*id == 'S' && *++id == 'O') || (*id == 'W' && *++id == 'E')
    || (*id == 'E' && *++id == 'A'))
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
        if (is_there_num(line))
            size++;
        free(line);
    }
    if (ret == 0 && line != NULL)
    {
        if (is_there_num(line))
            size++;
        free(line);
    }
    line = NULL;
    p->map.nb_lines = size;
    if (ret == -1)
	    return (quit(p, "Error with the file.\n"));
    if (close(fd) == -1)
	    return (quit(p, "Closing FD error.\n"));
    if (!(p->map.tab = (char **)malloc(sizeof(char *) * (size + 1))))
	    return (quit(p, "Error :\nMalloc failed.\n"));
    return (1);
}

int		parse_cub(t_param *p, int fd, char *path)
{
    int		ret;
    char	*line;

    ret = 0;
    line = NULL;
    p->map.mapY = 0;
    p->map.col_max = 0;
    if (!(malloc_lines(p, line, fd)))
	    return (0);
    fd = open_cub(p, path);
    while ((ret = get_next_line(fd, &line)))
    {
	    p->map.mapX = ft_strlen2(line);
	    if (!(parse_map(p, line)))
	    {
		    free(line);
            line = NULL;
		    return (quit(p, "Error :\nProblem with the map.\n"));
	    }
	    free(line);
    }
    if (ret == 0 && line != NULL)
    {	
        p->map.mapX = ft_strlen2(line);
        if (!(parse_map(p, line)))
	    {
		    free(line);
            line = NULL;
		    return (quit(p, "Error :\nProblem with the map.\n"));
	    }
	    free(line);
    }
    line = NULL;
    open_parse_err(p);
    if (ret == -1)
	    return (quit(p, "Error :\nwith the file.\n"));
    if (close(fd) == -1)
	    return (quit(p, "Closing FD error.\n"));
    return (1);
}

int	open_cub(t_param *p, char *path)
{
	int	fd;

	fd = 0;
	if (ft_strlen(path) < 4)
	    return (quit(p, "Error :\nNot a cub file.\n"));
	if (!(ft_strstr(path, ".cub")))
	    return (quit(p, "Error :\nNot a '.cub' file.\n"));
	else if ((fd = open(path, O_RDONLY)) == -1)
		return (quit(p, "Error :\nFD problem.\n"));
	return (fd);
}
