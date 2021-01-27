#include "cub3d.h"

void    get_tex_path(t_param *p)
{
    p->img.no = mlx_xpm_file_to_image(p->vars.mlx_ptr, p->text.no_path, &p->text.no_width, &p->text.no_height);
    p->text.no_addr = mlx_get_data_addr(p->img.no, &(p->img.bits_per_pixel_no), &(p->img.line_length_no), &(p->img.endian_no));
    p->img.so = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.so_path, &p->text.so_width, &p->text.so_height);
    p->text.so_addr = mlx_get_data_addr(p->img.so, &(p->img.bits_per_pixel_so), &(p->img.line_length_so), &(p->img.endian_so));
    p->img.we = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.we_path, &p->text.we_width, &p->text.we_height);
    p->text.we_addr = mlx_get_data_addr(p->img.we, &(p->img.bits_per_pixel_we), &(p->img.line_length_we), &(p->img.endian_we));
    p->img.ea = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.ea_path, &p->text.ea_width, &p->text.ea_height);
    p->text.ea_addr = mlx_get_data_addr(p->img.ea, &(p->img.bits_per_pixel_ea), &(p->img.line_length_ea), &(p->img.endian_ea));
    p->text.tex_height = 0;
    p->text.tex_width = 0;
}