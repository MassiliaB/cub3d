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
    p->img.sprite = mlx_xpm_file_to_image(p->vars.mlx_ptr,  p->text.sprite_path, &p->text.sp_width, &p->text.sp_height);
    p->text.sp_addr = mlx_get_data_addr(p->img.sprite, &(p->img.bits_per_pixel_sp), &(p->img.line_length_sp), &(p->img.endian_sp));
    p->text.tex_height = 0;
    p->text.tex_width = 0;
    p->sprite.buff = (double *)malloc(sizeof(double) * p->win_width + 1);
    p->sprite.sprite_order = (int *)malloc(sizeof(int) * p->sprite.num_sprites);
    p->sprite.sprite_dist = (int *)malloc(sizeof(int) * p->sprite.num_sprites);
}

void    put_sprite_on(t_param *p, int i)
{
    int d;

    p->sprite.stripe = p->sprite.draw_startX;
    while (p->sprite.stripe < p->sprite.draw_endX)
    {
        p->sprite.texX = (int)(256 * (p->sprite.stripe -(-p->sprite.sprite_width / 2 + p->sprite.sprite_screenX)) * (p->text.tex_width / p->sprite.sprite_width) / 256);
        p->sprite.y = p->sprite.draw_startY;
        if (p->sprite.transformY > 0 && p->sprite.stripe > 0 && p->sprite.stripe < p->win_width && p->sprite.transformY < p->sprite.buff[p->sprite.stripe])
        {
            while (p->sprite.y < p->sprite.draw_endX)
            {
                d = p->sprite.y * (256 - p->win_height * 128 + p->sprite.sprite_height * 128);
                p->sprite.texY = ((d * p->sprite.tex_height) / p->sprite.sprite_height) / 256;
                if (*(p->text.sp_addr + p->sprite.texX + p->sprite.texY * p->text.line_length_sp / 4))
                   *(p->text.img_addr + p->sprite.stripe + p->sprite.y * p->text.line_length / 4) = *(p->text.sp_addr + p->sprite.texX + p->sprite.texY * p->text.line_length_sp / 4);
                p->sprite.y++;
            }
        }
        p->sprite.stripe++;
    }
}

void    sort_sprite(t_param *p, int *order, double *dist)
{
    int i;

    i = 0;
    while (i < p->sprite.num_sprites)
    {
        p->sprite[i].first = dist[i];
        p->sprite[i].second = order[i];
        i++;
    }
    i = 0;
    while (i < p->sprite.num_sprites)
    {
        dist[i] = p->sprite[p->sprite.num_sprites - i - 1].first;
        order[i] = p->sprite[p->sprite.num_sprites - i - 1].second;
    }
}

void    sprite_casting(t_param *p)
{
    int i;

    i = 0;
    while (i < p->sprite.num_sprites)
    {
        p->sprite.sprite_order[i] = i;
        p->sprite.sprite_dist[i] = ((p->horizon.posX - p->sprite[i].x) * (p->horizon.posX - p->sprite[i].x) + (p->horizon.posY - p->sprite[i].y) * (p->horizon.posY - p->sprite[i].y));
        i++;
    }
    sort_sprite(p, p->sprite.sprite_order, p->sprite.sprite_dist);
    i = 0;
    while (i < p->sprite.num_sprites)
    {
        p->sprite.spriteX = p->sprite[p->sprite.sprite_order[i]].x - p->horizon.posX;
        p->sprite.spriteY = p->sprite[p->sprite.sprite_order[i]].y - p->horizon.posY;
        p->sprite.invDet = 1.0 / (p->horizon.planeX * p->horizon.dirY - p->horizon.dirX * p->horizon.planeY);
        p->sprite.transformX = p->sprite.invDet * (p->horizon.dirY * p->sprite.spriteX - p->horizon.dirX * p->sprite.spriteY);
        p->sprite.transformY = p->sprite.invDet * (-p->horizon.planeY * p->sprite.spriteX + p->horizon.planeX * p->sprite.spriteY);
        p->sprite.sprite_screenX = (int)((p->win_width /2) * (1 + p->sprite.transformX / p->sprite.transformY));
        p->sprite.sprite_height = abs((int)(p->win_height / p->sprite.transformY));
        p->sprite.draw_startY = -p->sprite.sprite_height / 2 + p->win_height / 2;
        if (p->sprite.draw_startY < 0)
            p->sprite.draw_startY = 0;
        p->sprite.draw_endY = p->sprite.sprite_height / 2 + p->win_height / 2;
        if (p->sprite.draw_endY >= p->win_height)
            p->sprite.draw_endY = p->win_height - 1;
        p->sprite.sprite_width = abs((int)(p->win_height / p->sprite.transformY));
        p->sprite.draw_startX = -p->sprite.sprite_width / 2 + p->sprite.sprite_screenX;
        if (p->sprite.draw_startX < 0)
            p->sprite.draw_startX = 0;
        p->sprite.draw_endX = p->sprite.sprite_width / 2 + p->sprite.sprite_screenX;
        if (p->sprite.draw_endX >= p->win_width)
            p->sprite.draw_endX = p->win_width - 1;
        put_sprite_on(p);
        i++;
    }
}