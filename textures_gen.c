#include "cub3d.h"

void    get_tex_path(t_param *p)
{
    p->img.no = mlx_xpm_file_to_image(p->vars.mlx_ptr, p->text.no_path, &p->text.tex_width, &p->text.tex_height);
    p->text.no_addr = mlx_get_data_addr(p->img.no, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian));
    
    p->img.so = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.no_path, &p->text.tex_width, &p->text.tex_height);
    p->text.so_addr = mlx_get_data_addr(p->img.so, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian));
    
    p->img.we = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.no_path, &p->text.tex_width, &p->text.tex_height);
    p->text.we_addr = mlx_get_data_addr(p->img.we, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian));
    
    p->img.ea = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.no_path, &p->text.tex_width, &p->text.tex_height);
    p->text.ea_addr = mlx_get_data_addr(p->img.ea, &(p->img.bits_per_pixel), &(p->img.line_length), &(p->img.endian));
}

