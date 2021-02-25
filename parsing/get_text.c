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
	int i;

	i = 0;
	if (p->text.no_path != NULL)
		return (quit(p, "Error :\nYou have two NO.\n", NULL));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_'
	|| (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.'
		|| line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.'
			&& line[i] != '/' && !ft_isdigit(line[i]))
				return (quit(p, "Error :\nInvalid path texture NO.\n", line));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm NO file.\n", line));
		p->text.no_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for texture NO.\n", line));
	return (1);
}

int		get_so(char *line, t_param *p)
{
	int i;

	i = 0;
	if (p->text.so_path != NULL)
		return (quit(p, "Error :\nYou have two SO.\n", NULL));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_'
	|| (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_'
		|| line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.'
			&& line[i] != '/' && !ft_isdigit(line[i]))
				return (quit(p, "Error :\nInvalid path texture SO.\n", line));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm SO file.\n", line));
		p->text.so_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for texture SO.\n", line));
	return (1);
}

int		get_we(char *line, t_param *p)
{
	int i;

	i = 0;
	if (p->text.we_path != NULL)
		return (quit(p, "Error :\nYou have two WE.\n", NULL));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_'
	|| (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.'
		|| line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.'
			&& line[i] != '/' && !ft_isdigit(line[i]))
				return (quit(p, "Error :\nInvalid path texture WE.\n", line));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm WE file.\n", line));
		p->text.we_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for texture WE.\n", line));
	return (1);
}

int		get_ea(char *line, t_param *p)
{
	int i;

	i = 0;
	if (p->text.ea_path != NULL)
		return (quit(p, "Error :\nYou have two EA.\n", NULL));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_'
	|| (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.'
		|| line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.'
			&& line[i] != '/' && !ft_isdigit(line[i]))
				return (quit(p, "Error :\nInvalid path texture EA.\n", line));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm EA file.\n", line));
		p->text.ea_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for texture EA.\n", line));
	return (1);
}

int		get_sprite(char *line, t_param *p)
{
	int i;

	i = 0;
	if (p->text.sprite_path != NULL)
		return (quit(p, "Error :\nYou put two sprites.\n", NULL));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_'
	|| (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.'
		|| line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.'
			&& line[i] != '/' && !ft_isdigit(line[i]))
				return (quit(p, "Error :\nInvalid path for sprite.\n", line));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm SPRITE file.\n", line));
		p->text.sprite_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for your sprite.\n", line));
	return (1);
}
