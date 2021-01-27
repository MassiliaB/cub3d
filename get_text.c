#include "cub3d.h"

int	get_no(char *line, t_param *p)
{
	int i;
	
	i = 0;
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid texture file.\n"));
		p->text.no_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nWrong path for texture.\n"));
	return (1);
}
int	get_so(char *line, t_param *p)
{
	int i;
	
	i = 0;
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid texture file.\n"));
		p->text.so_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nWrong path for texture.\n"));
	return (1);
}

int	get_we(char *line, t_param *p)
{
	int i;
	
	i = 0;
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid texture file.\n"));
		p->text.we_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nWrong path for texture.\n"));
	return (1);
}

int	get_ea(char *line, t_param *p)
{
	int i;
	
	i = 0;
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid texture file.\n"));
		p->text.ea_path = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nWrong path for texture.\n"));
	return (1);
}

int	get_sprite(char *line, t_param *p)
{
	int i;
	
	i = 0;
	while (*line == ' ')
		line++;
	if (ft_isalpha(*line) || *line == '_' || (*line == '.' && *(line + 1) == '/'))
	{
		while (ft_isalpha(line[i]) || line[i] == '_' || line[i] == '.' || line[i] == '/' || ft_isdigit(line[i]))
		{
			if (!ft_isalpha(line[i]) && line[i] != '_' && line[i] != '.' && line[i] != '/' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			i++;
		}
		if (!(ft_strstr(line, ".xpm")))
			return (quit(p, "Error :\nInvalid texture file.\n"));
		p->text.sprite = ft_strdup(line);
	}
	else
		return (quit(p, "Error :\nWrong path for texture.\n"));
	return (1);
}