#include "cub3d.h"

int	get_no(char *line, t_param *p)
{
	int i;
	
	i = 0;
	if (p->text.no_path != 0)
		return (quit(p, "Error :\nYou have two NO.\n"));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error :\nInvalid path for texture NO.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm NO file.\n"));
		p->text.no_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for texture NO.\n"));
	return (1);
}
int	get_so(char *line, t_param *p)
{
	int i;
	
	i = 0;
	if (p->text.so_path != 0)
		return (quit(p, "Error :\nYou have two SO.\n"));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error :\nInvalid path for texture SO.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm SO file.\n"));
		p->text.so_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for texture SO.\n"));
	return (1);
}

int	get_we(char *line, t_param *p)
{
	int i;
	
	i = 0;
	if (p->text.we_path != 0)
		return (quit(p, "Error :\nYou have two WE.\n"));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error :\nInvalid path for texture WE.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm WE file.\n"));
		p->text.we_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for texture WE.\n"));
	return (1);
}

int	get_ea(char *line, t_param *p)
{
	int i;
	
	i = 0;
	if (p->text.ea_path != 0)
		return (quit(p, "Error :\nYou have two EA.\n"));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error :\nInvalid path for texture EA.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm EA file.\n"));
		p->text.ea_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for texture EA.\n"));
	return (1);
}

int	get_sprite(char *line, t_param *p)
{
	int i;
	
	i = 0;
	if (p->text.sprite_path != 0)
		return (quit(p, "Error :\nYou put two sprite.\n"));
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(line[i]))
				return (quit(p, "Error :\nInvalid path for your sprite2.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid xpm SPRITE file.\n"));
		p->text.sprite_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nInvalid path for your sprite.\n"));
	return (1);
}