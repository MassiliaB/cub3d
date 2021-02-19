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
    while (i < p->sprite.num_sprites - 1)
    {
        if (p->sprite.sprite_dist[i] < p->sprite.sprite_dist[i + 1])
        {
            tmp = p->sprite.sprite_dist[i];
            p->sprite.sprite_dist[i] = p->sprite.sprite_dist[i + 1];
            p->sprite.sprite_dist[i + 1] = tmp;
            tmp = p->sprite.sprite_order[i];
            p->sprite.sprite_order[i] = p->sprite.sprite_order[i + 1];
            p->sprite.sprite_order[i + 1] = tmp;
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
      //  printf("coucou7\n");
        p->sprite.spriteX = p->sprite_ptr[p->sprite.sprite_order[i]].x
        - p->horizon.posX;
      //          printf("---1\n");
        p->sprite.spriteY = p->sprite_ptr[p->sprite.sprite_order[i]].y
        - p->horizon.posY;
       //                 printf("---2\n");
        p->sprite.invDet = 1.0 / (p->horizon.planeX * p->horizon.dirY
        - p->horizon.dirX * p->horizon.planeY);
       //                 printf("---3\n");
        p->sprite.transformX = p->sprite.invDet * (p->horizon.dirY
        * p->sprite.spriteX - p->horizon.dirX * p->sprite.spriteY);
       //                 printf("---4\n");
        p->sprite.transformY = p->sprite.invDet * (-p->horizon.planeY
        * p->sprite.spriteX + p->horizon.planeX * p->sprite.spriteY);
       //                 printf("---5\n");
        p->sprite.sprite_screenX = (int)((p->win_width /2)
        * (1 + p->sprite.transformX / p->sprite.transformY));
        
    //    printf("p->sprite.spriteY [%f], p->sprite.spriteX [%f], p->sprite.invDet [%f], p->sprite.transformX[%f]], p->sprite.transformY[%f], p->sprite.sprite_screenX[%d]\n",p->sprite.spriteY, p->sprite.spriteX,p->sprite.invDet, p->sprite.transformX, p->sprite.transformY, p->sprite.sprite_screenX);

        sprite_height(p);
    //    printf("coucou8\n");
        sprite_width(p);
    //    printf("coucou9\n");
        put_sprite_on(p);
    //    printf("coucou10\n");
        i++;
    }
}
