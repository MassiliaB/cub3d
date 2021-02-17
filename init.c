#include "inc/cub3d.h"

int     word_check(char *str, char *comp)
{
    while (*str)
    {
        if (*str != *comp)
            return (0);
        str++;
        comp++;
    }
    return (1);
}

void    get_tex_path(t_param *p)
{
    p->img.no = mlx_xpm_file_to_image(p->vars.mlx_ptr, p->text.no_path, &p->text.no_width, &p->text.no_height);
    p->text.no_addr = mlx_get_data_addr(p->img.no, &p->img.bits_per_pixel_no, &p->img.line_length_no, &p->img.endian_no);
    p->img.so = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.so_path, &p->text.so_width, &p->text.so_height);
    p->text.so_addr = mlx_get_data_addr(p->img.so, &(p->img.bits_per_pixel_so), &(p->img.line_length_so), &(p->img.endian_so));
    p->img.we = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.we_path, &p->text.we_width, &p->text.we_height);
    p->text.we_addr = mlx_get_data_addr(p->img.we, &(p->img.bits_per_pixel_we), &(p->img.line_length_we), &(p->img.endian_we));
    p->img.ea = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.ea_path, &p->text.ea_width, &p->text.ea_height);
    p->text.ea_addr = mlx_get_data_addr(p->img.ea, &(p->img.bits_per_pixel_ea), &(p->img.line_length_ea), &(p->img.endian_ea));
    p->img.sprite = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.sprite_path, &p->text.sp_width, &p->text.sp_height);
    p->text.sp_addr = mlx_get_data_addr(p->img.sprite, &(p->img.bits_per_pixel_sp), &(p->img.line_length_sp), &(p->img.endian_sp));
    p->text.tex_height = 0;
    p->text.tex_width = 0;
}

t_sprites_ptr    *get_sprites_pos(t_param *p)
{
    t_sprites_ptr *sprite_ptr;
    int x;
    int y;
    int i;

    if (!(p->sprite.sprite_order = (int *)malloc(sizeof(int) * p->sprite.num_sprites + 1)))
        return (0);
    if (!(p->sprite.sprite_dist = (double *)malloc(sizeof(double) * p->sprite.num_sprites + 1)))
        return (0);
    if (!(sprite_ptr = malloc(sizeof(t_sprites_ptr) * p->sprite.num_sprites)))
        return (0);
    i = 0;
    y = 0;
    while (y < p->map.mapY)
    {
        x = 0;
        p->map.mapX = ft_strlen2(p->map.tab[y]);
		while (x < p->map.mapX)
		{
            if (p->map.tab[y][x] == '2')
            {
                sprite_ptr[i].x = (double)x + 0.5;
                sprite_ptr[i].y = (double)y + 0.5;
                i++;
            }
            x++;
        }
        y++;
    }
    return (sprite_ptr);
}

void	init_img(t_param *p)
{
	p->colors.wall = creat_trgb(0, 47, 95, 95);
    p->colors.floor = creat_trgb(1, p->colors.floor_r, p->colors.floor_g, p->colors.floor_b);
    p->colors.sky = creat_trgb(0, p->colors.sky_r, p->colors.sky_g, p->colors.sky_b);
    p->colors.sprite = creat_trgb(0, 153, 0, 26);
    p->sprite_ptr = get_sprites_pos(p);
}

void	init_player(t_param *p)
{
    p->map.tab = NULL;
    p->horizon.movespeed =  0.20;
    p->horizon.rotspeed =  0.05;
    p->touch = 0;
    p->sprite.num_sprites = 0;
    p->fps.rot_right = 0;
    p->fps.rot_left = 0;
    p->fps.forward = 0;
    p->fps.backward = 0;
    p->fps.left = 0;
    p->fps.right = 0;
    p->text.sprite_path = NULL;
    p->text.ea_path = NULL;
    p->text.we_path = NULL;
    p->text.so_path = NULL;
    p->text.no_path = NULL;
    p->win_height = 0;
    p->win_width = 0;
    p->colors.floor_r = 0;
    p->colors.floor_g = 0;
    p->colors.floor_b = 0;
    p->colors.sky_g  = 0;
    p->colors.sky_r = 0;
    p->colors.sky_b = 0;
    p->horizon.view = 0;
    p->map.nb_lines = 0;
    p->map.col_max = 0;
    p->map.mapX = 0;
    p->map.mapY = 0;
    p->sprite_ptr = NULL;
    p->sprite.sprite_order = 0;
    p->sprite.sprite_dist = 0;
}