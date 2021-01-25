#include "cub3d.h"

int	get_no(char *line, t_param *p)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "./", 2) == 0)
	{
		line += 2;
		if (!ft_isalpha(*line))
			return (quit(p, "Error : wrong path for texture.\n"));
		while (ft_isalpha(*line) || *line == '_' || ft_isdigit(*line))
		{
			if (!ft_isalpha(*line) && *line != '_' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			line++;
		}
		p->text.no = ft_strdup(line);
	}
	else
		return (quit(p, "Error : 1wrong path for texture.\n"));
	return (1);
}
int	get_so(char *line, t_param *p)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "./", 2) == 0)
	{
		line += 2;
		if (!ft_isalpha(*line))
			return (quit(p, "Error : wrong path for texture.\n"));
		while (ft_isalpha(*line) || *line == '_' || ft_isdigit(*line))
		{
			if (!ft_isalpha(*line) && *line != '_' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			line++;
		}
		p->text.so = ft_strdup(line);
	}
	else
		return (quit(p, "Error : wrong path for texture.\n"));
	return (1);
}

int	get_we(char *line, t_param *p)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "./", 2) == 0)
	{
		line += 2;
		if (!ft_isalpha(*line))
			return (quit(p, "Error : wrong path for texture.\n"));
		while (ft_isalpha(*line) || *line == '_' || ft_isdigit(*line))
		{
			if (!ft_isalpha(*line) && *line != '_' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			line++;
		}
		p->text.we = ft_strdup(line);
	}
	else
		return (quit(p, "Error : wrong path for texture.\n"));
	return (1);
}

int	get_ea(char *line, t_param *p)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "./", 2) == 0)
	{
		line += 2;
		if (!ft_isalpha(*line))
			return (quit(p, "Error : wrong path for texture.\n"));
		while (ft_isalpha(*line) || *line == '_' || ft_isdigit(*line))
		{
			if (!ft_isalpha(*line) && *line != '_' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			line++;
		}
		p->text.ea = ft_strdup(line);
	}
	else
		return (quit(p, "Error : wrong path for texture.\n"));
	return (1);
}

int	get_sprite(char *line, t_param *p)
{
	if (ft_strncmp(line, "./", 2) == 0)
	{
		line += 2;
		if (!ft_isalpha(*line))
			return (quit(p, "Error : wrong path for texture.\n"));
		while (ft_isalpha(*line) || *line == '_' || ft_isdigit(*line))
		{
			if (!ft_isalpha(*line) && *line != '_' && !ft_isdigit(*line))
				return (quit(p, "Error : 3wrong path for texture.\n"));
			line++;
		}
		p->text.sprite = ft_strdup(line);
	}
	else
		return (quit(p, "Error : wrong path for texture.\n"));
	return (1);
}