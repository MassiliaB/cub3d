
#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_texture
{
	char *no_path;
	char    *no_addr;
	char *so_path;
	char    *so_addr;
	char *we_path;
	char    *we_addr;
	char *ea_path;
	char    *ea_addr;
	char *sprite_path;
	char *sp_addr;
	int		tex_width;
	int		tex_height;
	int 	tex_num;
	double	wallX;
	int		texX;
	char *tex_addr;
	double step;
	double tex_pos;
	int		texY;
	char wall_dir;
	char *img_addr;
	int		no_width;
	int		no_height;
	int		so_width;
	int		so_height;
	int		we_width;
	int		we_height;
	int		ea_width;
	int		ea_height;
	int		sp_width;
	int		sp_height;
	int		bpp;
	int ll;

}			t_texture;
typedef struct s_sprites
{
	double	x;
	double	y;
	int		first;
	int 	second;
}				t_sprites;
typedef struct s_sprites_utils
{
	int tex;
	double *buff;
	double	sprite_dist;
	int		*sprite_order;
	double	spriteX;
	double spriteY;
	double invDet;
	double transformX;
	double transformY;
	int		sprite_screenX;
	int		sprite_height;
	int		sprite_width;
	int stripe;
	int texX;
	int	texY;
	int draw_startY;
    int draw_startX;
    int draw_endY;
    int draw_endX;
    
}				t_sprites_utils;

typedef struct s_player
{
    double  rad;
	int		forward;
	int		backward;	
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
	double rot_angle;
	int 	x;
	int 	y;
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
	void	*no;
	int		bits_per_pixel_no;
	int     line_length_no;
	int     endian_no;
	void	*so;
	int		bits_per_pixel_so;
	int     line_length_so;
	int     endian_so;
	void	*we;
	int		bits_per_pixel_we;
	int     line_length_we;
	int     endian_we;
	void	*ea;
	int		bits_per_pixel_ea;
	int     line_length_ea;
	int     endian_ea;
	void	*sprite;
	int		bits_per_pixel_sp;
	int     line_length_sp;
	int     endian_sp;
}				t_img;


typedef struct s_map
{
	int		mapX;
	int		mapY;
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
	int		sprite;
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
	int draw_start;
	int line_height;
	int draw_end;
}				t_draw;

typedef struct s_param
{
	t_mlx	vars;
	t_img	img;
	t_map	map;
	t_sprites sprit;
	t_sprites_utils sprite;
	t_player fps;
	t_horizon horizon;
	t_colors colors;
	t_draw	draw;
	t_texture text;
	int	win_width;
	int 	win_height;
	int touch;
}               t_param;


#endif
