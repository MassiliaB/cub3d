#include "../inc/cub3d.h"

void    put_sprite_on(t_param *p)
{
    char *color;
    int color2; //modif guig
    p->sprite.stripe = p->draw.draw_startX;
    while (p->sprite.stripe < p->draw.draw_endX)
    {
        p->sprite.texX = (int)(256 * (p->sprite.stripe -(-p->sprite.sprite_width
        / 2 + p->sprite.sprite_screenX)) * p->text.sp_width / p->sprite.sprite_width) / 256; // / 200 adapté au vol
        if (p->sprite.transformY > 0 && p->sprite.stripe > 0 && p->sprite.stripe < p->win_width
        && p->sprite.transformY < p->sprite.buff[p->sprite.stripe])
        {
            p->sprite.y = p->draw.draw_startY;
            while (p->sprite.y < p->draw.draw_endY)
            {
                p->sprite.d = (p->sprite.y) * 256 - p->win_height * 128 + p->sprite.sprite_height * 128;
                p->sprite.texY = ((p->sprite.d * p->text.sp_height) / p->sprite.sprite_height) / 256; // -> / 200 vol dans les airs
                color = (char *)(p->text.sp_addr + p->sprite.texY * p->img.line_length_sp + p->sprite.texX * p->text.bpp / 8);
            //   printf("color [%s]\n", color);
                color2 = *(unsigned int*)color;
                if (color2 && 0x00FFFFFF != 0)
                    my_mlx_pixel_put(p, p->sprite.stripe, p->sprite.y, color2);
                p->sprite.y++;
            }
        }
        p->sprite.stripe++;
    }
}

void    put_tex_on(t_param *p, int x)
{
    int y;
    char *color;
    int color2;

    y = p->draw.draw_start;
    while (y < p->draw.draw_end)
    {
        p->text.texY = (int)p->text.tex_pos & (p->text.tex_height - 1);
        p->text.tex_pos += p->text.step;
        color = (char *)(p->text.img_addr + p->text.texY * p->text.ll + p->text.texX * (p->text.bpp / 8));
        color2 = *(unsigned int*)color; 
        if (p->horizon.side == 1)
            color2 = (color2 >> 1) & 8355711;
        my_mlx_pixel_put(p, x, y, color2);
        y++;
    } 
    p->sprite.buff[x] = p->horizon.perpwalldist;
}
void    tex_side(t_param *p)
{
    if (p->horizon.side == 0)
    {
        if (p->horizon.rayDirX > 0)
        {
            p->text.wall_dir = 'E';
            p->text.texX = p->text.tex_width - p->text.texX - 1;
        }
        else
            p->text.wall_dir = 'W';
    }
    if (p->horizon.side == 1)
    {
        if (p->horizon.rayDirY < 0)
        {
            p->text.wall_dir = 'N';
            p->text.texX = p->text.tex_width - p->text.texX - 1;
        }
        else
            p->text.wall_dir = 'S';
    }
    
}

void    wall_tex_value(t_param *p, int x)
{
    p->text.tex_num = p->map.tab[p->horizon.currentposY][p->horizon.currentposX] - 1;
    if (p->horizon.side == 0)
        p->text.wallX = p->horizon.posY + p->horizon.perpwalldist * p->horizon.rayDirY;
    else
        p->text.wallX = p->horizon.posX + p->horizon.perpwalldist * p->horizon.rayDirX;
    p->text.wallX -= floor(p->text.wallX);
    p->text.texX = (int)(p->text.wallX * (double)p->text.tex_width);
    tex_side(p);
    choose_wall_dirNS(p);
    put_tex_on(p, x);
}