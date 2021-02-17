#include "../inc/cub3d.h"


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
void    sprite_height(t_param *p)
{
    p->sprite.sprite_height = abs((int)(p->win_height
    / p->sprite.transformY));
    p->draw.draw_startY = -p->sprite.sprite_height
    / 2 + p->win_height / 2;
    if (p->draw.draw_startY < 0)
        p->draw.draw_startY = 0;
    p->draw.draw_endY = p->sprite.sprite_height
    / 2 + p->win_height / 2;
    if (p->draw.draw_endY >= p->win_height)
        p->draw.draw_endY = p->win_height - 1;
}

void    sprite_width(t_param *p)
{
    p->sprite.sprite_width = abs((int)(p->win_height / p->sprite.transformY));
    p->draw.draw_startX = -p->sprite.sprite_width / 2 + p->sprite.sprite_screenX;
    if (p->draw.draw_startX < 0)
        p->draw.draw_startX = 0;
    p->draw.draw_endX = p->sprite.sprite_width / 2 + p->sprite.sprite_screenX;
    if (p->draw.draw_endX >= p->win_width)
        p->draw.draw_endX = p->win_width - 1;
}

void    sprite_casting(t_param *p)
{
    int i;

    sort_sprite(p);
    i = 0;
    while (i < p->sprite.num_sprites)
    {
        p->sprite.spriteX = p->sprite_ptr[p->sprite.sprite_order[i]].x + 0.5
        - p->horizon.posX;
        p->sprite.spriteY = p->sprite_ptr[p->sprite.sprite_order[i]].y + 0.5
        - p->horizon.posY;
        p->sprite.invDet = 1.0 / (p->horizon.planeX * p->horizon.dirY
        - p->horizon.dirX * p->horizon.planeY);
        p->sprite.transformX = p->sprite.invDet * (p->horizon.dirY
        * p->sprite.spriteX - p->horizon.dirX * p->sprite.spriteY);
        p->sprite.transformY = p->sprite.invDet * (-p->horizon.planeY
        * p->sprite.spriteX + p->horizon.planeX * p->sprite.spriteY);
        p->sprite.sprite_screenX = (int)((p->win_width /2)
        * (1 + p->sprite.transformX / p->sprite.transformY));
        sprite_height(p);
        sprite_width(p);
        put_sprite_on(p);
        i++;
    }
}