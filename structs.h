#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"
# define Width 880
# define Height 550

typedef struct	s_mlx
{
	void    *mlx_ptr;
	void    *win_ptr;
}				t_mlx;

typedef struct s_img
{
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}				t_img;


typedef struct s_map
{
	int		mapX;
	int		mapY;
	int		tile_size;
	char		**tab;
	int		nb_lines;
	int		line_max;
}               t_map;

typedef struct s_colors
{
	int		floor;
	int		sky;
	int		wall;
	int		person;
	int		sky_r;
	int		sky_g;
	int		sky_b;
	int		floor_r;
	int		floor_g;
	int		floor_b;

}				t_colors;

typedef struct s_horizon
{
	double  deltaX;
	double  deltaY;
	double  pixelX;
	double  pixelY;
	double  posX;
	double  posY;
	double  dirX;
	double  dirY;
	double  planeX;
	double  planeY;
	double  cameraX;
	double  rayDirX;
	double  rayDirY;
	double  perpWallDist;
	int     stepX;
	int     stepY;
	double  sideDistX;
	double  sideDistY;
	double  deltaDistX;
	double  deltaDistY;
	char	view;
	char	view_nu;
}               t_horizon;

typedef struct s_param
{
	t_mlx	vars;
	t_img	img;
	t_map	map;
	t_horizon person;
	t_colors colors;
	int	win_width;
	int 	win_height;
}               t_param;


#endif
