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
	    return (quit(p, "Failed to malloc the array.\n"));
    return (1);
}

int		parse_no_error(t_param *p, int fd, char *path)
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
		    return (quit(p, "YError with the map.\n"));
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
		    return (quit(p, "HError with the map.\n"));
	    }
	    free(line);
    }
    line = NULL;
    if (!(check_col(p)))
	    return (quit(p, "LError with the map.\n"));
    if (!p->text.no_path || !p->text.so_path || !p->text.we_path || !p->text.ea_path)
        return (quit(p, "Error :\nMissing texture.\n"));
    if (!(ft_isview(p->horizon.view, p)))
	    return (quit(p, "Error with the player on the map.\n"));
    if (ret == -1)
	    return (quit(p, "Error with the file.\n"));
    if (close(fd) == -1)
	    return (quit(p, "Closing FD error.\n"));
    return (1);
}

int	open_cub(t_param *p, char *path)
{
	int	fd;

	fd = 0;
	if (ft_strlen(path) < 4)
	    return (quit(p, "Not a cub file.\n"));
	if (!(ft_strstr(path, ".cub")))
	    return (quit(p, "Not a '.cub' file.\n"));
	else if ((fd = open(path, O_RDONLY)) == -1)
		return (quit(p, "FD Error.\n"));
	return (fd);
}
