/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:52:35 by masboula          #+#    #+#             */
/*   Updated: 2021/03/03 12:51:17 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	close_fd(t_param *p, int fd, int ret)
{
	if (ret == -1)
		return (quit(p, "Error :\nReading file -1.\n", NULL));
	if (close(fd) == -1)
		return (quit(p, "Error :\nClosing FD failed.\n", NULL));
	return (1);
}

int	malloc_lines(t_param *p, char *line, int fd)
{
	int	ret;

	ret = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (is_there_num(line))
			p->map.nb_lines++;
		free(line);
	}
	if (ret == 0 && line != NULL)
	{
		if (is_there_num(line))
			p->map.nb_lines++;
		free(line);
	}
	line = NULL;
	if (!close_fd(p, ret, fd))
		return (quit(p, "Error :\nwhy.\n", NULL));
	if (p->map.nb_lines == 0)
		return (quit(p, "Error :\nWhere is the map ?\n", NULL));
	if (!(p->map.tab = (char **)malloc(sizeof(char *) * (p->map.nb_lines + 1))))
		return (quit(p, "Error :\nMalloc of the array failed.\n", NULL));
	p->map.tab[p->map.nb_lines] = '\0';
	return (1);
}

int	parse_cub(t_param *p, int fd, char *path)
{
	int		ret;
	char	*line;

	ret = 0;
	line = NULL;
	malloc_lines(p, line, fd);
	fd = open_cub(p, path);
	while ((ret = get_next_line(fd, &line)))
	{
		p->map.mapx = ft_strlen2(line);
		if (!(parse_map(p, line)))
			return (quit(p, "Error :\nProblem with the map.\n", line));
		free(line);
	}
	if (ret == 0 && line != NULL)
	{
		p->map.mapx = ft_strlen2(line);
		if (!(parse_map(p, line)))
			return (quit(p, "Error :\nProblem with the map.\n", line));
		free(line);
	}
	line = NULL;
	parse_error(p);
	close_fd(p, fd, ret);
	return (1);
}

int	open_cub(t_param *p, char *path)
{
	int	fd;

	fd = 0;
	if (ft_strlen(path) < 4)
		return (quit(p, "Error :\nNot a cub file.\n", NULL));
	if (!(ft_strstr(path, ".cub")))
		return (quit(p, "Error :\nNot a '.cub' file.\n", NULL));
	else if ((fd = open(path, O_RDWR)) == -1)
		return (quit(p, "Error :\nFD problem.\n", NULL));
	return (fd);
}
