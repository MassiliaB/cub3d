#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"
# define Width 880
# define Height 550

typedef struct s_player
{
    double  rad;
	double  vec; //the player (pos & direction)*/
	int		forward;
	int		backward;	
	int		left;
	int		right;
	int rotleft;
	int rotright;
	int	    x;
    int	    y;
}		t_player;

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
	char	**tab;
	int		nb_lines;
	int		col_max;
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
	double angle; //fov 2* atan(planY/1.0) == 66 degres
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
	double  perpwalldist;
	int     stepX;
	int     stepY;
	double  sideDistX;
	double  sideDistY;
	double  deltaDistX;
	double  deltaDistY;
	char	view;
	char	view_nu;
	double 	time;
	double 	oldtime;
	int		side;
	int 	hit;
	double frameTime;
	double movespeed;
	double rotspeed;
	double oldDirX;
	double oldPlaneX;
	int currentposX;
	int currentposY;
 
}               t_horizon;

typedef struct s_draw
{
	int drawStart;
	int lineHeight;
	int drawEnd;
}				t_draw;

typedef struct s_param
{
	t_mlx	vars;
	t_img	img;
	t_map	map;
	t_player fps;
	t_horizon horizon;
	t_colors colors;
	t_draw	draw;
	int	win_width;
	int 	win_height;
}               t_param;


#endif
