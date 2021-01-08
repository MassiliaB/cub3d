/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:06:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 15:39:48 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_getline(char *str)
{
	int		i;
	char	*dest;
	int		l;

	l = ft_strlen(str);
	if (!(dest = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_is_line(int ret, char **line, char **str)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && !*str)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (!ft_strchr(*str, '\n'))
	{
		*line = ft_getline(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	*line = ft_getline(*str);
	ft_strdel(*str);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*str[FD_MAX];
	int			ret;
	char		*temp;

	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE <= 0
	|| (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (ft_is_line(ret, line, &str[fd]));
}
