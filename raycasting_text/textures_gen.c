#include "../inc/cub3d.h"

void    put_sprite_on(t_param *p)
{
    int color;
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
                color = p->text.sp_addr[p->sprite.texY * p->img.line_length_sp + p->sprite.texX * p->text.bpp / 8];
            //    printf("color = %d", color);
                if (color && 0x00FFFFFF != 0)
                    my_mlx_pixel_put(p, p->sprite.stripe, p->sprite.y, color);
                p->sprite.y++;
            }
        }
        p->sprite.stripe++;
    }
}

void    sort_sprite(t_param *p)
{
    int i;
    int tmp;

    i = 0;
    tmp = 0;
    while (i < p->sprite.num_sprites)
    {
        p->sprite.sprite_order[i] = i;
        p->sprite.sprite_dist[i] = ((p->horizon.posX - p->sprite_ptr[i].x) * (p->horizon.posX - p->sprite_ptr[i].x)
        + (p->horizon.posY - p->sprite_ptr[i].y) * (p->horizon.posY - p->sprite_ptr[i].y));
        i++;
    }
    i = 0;
    while (i < p->sprite.num_sprites)
    {
        if (p->sprite.sprite_dist[i] < p->sprite.sprite_dist[i + 1])
        {
            tmp = p->sprite.sprite_dist[i];
            p->sprite.sprite_dist[i] = p->sprite.sprite_dist[i + 1];
            p->sprite.sprite_dist[i + 1] = tmp;
            tmp = p->sprite.sprite_order[i];
            p->sprite.sprite_order[i] = p->sprite.sprite_order[i + 1];
            p->sprite.sprite_order[i + 1] = (int)tmp;
            i = 0;
        }
        else
            i++;
    }
}

void    sprite_casting(t_param *p)
{
    int i;

    sort_sprite(p);
    i = 0;
    while (i < p->sprite.num_sprites)
    {
        p->sprite.spriteX = p->sprite_ptr[p->sprite.sprite_order[i]].x - p->horizon.posX;
        p->sprite.spriteY = p->sprite_ptr[p->sprite.sprite_order[i]].y - p->horizon.posY;
      //  printf("[%d]\n", p->sprite.sprite_order[i]);
        p->sprite.invDet = 1.0 / (p->horizon.planeX * p->horizon.dirY - p->horizon.dirX * p->horizon.planeY);
        p->sprite.transformX = p->sprite.invDet * (p->horizon.dirY * p->sprite.spriteX - p->horizon.dirX * p->sprite.spriteY);
        p->sprite.transformY = p->sprite.invDet * (-p->horizon.planeY * p->sprite.spriteX + p->horizon.planeX * p->sprite.spriteY);
        p->sprite.sprite_screenX = (int)((p->win_width /2) * (1 + p->sprite.transformX / p->sprite.transformY));
    
        p->sprite.sprite_height = abs((int)(p->win_height / p->sprite.transformY));
        p->draw.draw_startY = -p->sprite.sprite_height / 2 + p->win_height / 2;
        if (p->draw.draw_startY < 0)
            p->draw.draw_startY = 0;
        p->draw.draw_endY = p->sprite.sprite_height / 2 + p->win_height / 2;
        if (p->draw.draw_endY >= p->win_height)
            p->draw.draw_endY = p->win_height - 1;

        p->sprite.sprite_width = abs((int)(p->win_height / p->sprite.transformY));
        p->draw.draw_startX = -p->sprite.sprite_width / 2 + p->sprite.sprite_screenX;
        if (p->draw.draw_startX < 0)
            p->draw.draw_startX = 0;
        p->draw.draw_endX = p->sprite.sprite_width / 2 + p->sprite.sprite_screenX;
        if (p->draw.draw_endX >= p->win_width)
            p->draw.draw_endX = p->win_width - 1;
        put_sprite_on(p);
        i++;
    }
}