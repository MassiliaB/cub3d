/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:49:27 by masboula          #+#    #+#             */
/*   Updated: 2021/02/23 16:52:22 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		get_no(char *line, t_param *p)
{
	if (p->text.no_path != NULL)
		return (quit(p, "Error :\nYou have two NO.\n", NULL));
	while (*line == ' ')
		line++;
	if (!(p->text.no_path = ft_strdup(line)))
		return (quit(p, "Error :\nYou have two NO.\n", NULL));
	return (1);
}

int		get_so(char *line, t_param *p)
{
	if (p->text.so_path != NULL)
		return (quit(p, "Error :\nYou have two SO.\n", NULL));
	while (*line == ' ')
		line++;
	if (!(p->text.so_path = ft_strdup(line)))
		return (quit(p, "Error :\nYou have two SO.\n", NULL));
	return (1);
}

int		get_we(char *line, t_param *p)
{
	if (p->text.we_path != NULL)
		return (quit(p, "Error :\nYou have two WE.\n", NULL));
	while (*line == ' ')
		line++;
	if (!(p->text.we_path = ft_strdup(line)))
		return (quit(p, "Error :\nYou have two WE.\n", NULL));
	return (1);
}

int		get_ea(char *line, t_param *p)
{
	if (p->text.ea_path != NULL)
		return (quit(p, "Error :\nYou have two EA.\n", NULL));
	while (*line == ' ')
		line++;
	if (!(p->text.ea_path = ft_strdup(line)))
		return (quit(p, "Error :\nYou have two EA.\n", NULL));
	return (1);
}

int		get_sprite(char *line, t_param *p)
{
	if (p->text.sprite_path != NULL)
		return (quit(p, "Error :\nYou put two sprites.\n", NULL));
	if (!(p->text.sprite_path = ft_strdup(line)))
		return (quit(p, "Error :\nYou put two sprites.\n", NULL));
	return (1);
}
