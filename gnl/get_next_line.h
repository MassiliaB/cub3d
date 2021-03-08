/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:29:53 by user42            #+#    #+#             */
/*   Updated: 2021/03/08 13:20:35 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 100

int		get_next_line(int fd, char **line);
char	*ft_strdup2(char *src);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(char *s, int c);
void	ft_strdel(char *str);
int		ft_strlen2(char *str);

#endif
