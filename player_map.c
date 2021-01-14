#include "cub3d.h"

void	init_player_map(t_param *p)
{ 
    p->fps.rad = 3;
    p->fps.dir_turn = 0;
    p->fps.dir_walk = 0;
    p->fps.rot_angle = M_PI / 2;
    p->fps.move_speed = 2.0;
    p->fps.rot_speed = 2 * (M_PI / 180);
}

void	line_dir(t_param *p, int x, int y, int color)
{
    p->fps.x + cos(p->fps.rot_angle) * 30;
    p->fps.y + cos(p->fps.rot_angle) * 30;
    my_mlx_pixel_put(p, p->fps.x, p->fps.y, color);
}

void	display_circle_map(t_param *p, int x, int y, int width)
{
    int	i;
    int j;
    double dist;
 
    p->colors.person = creat_trgb(0, 255, 255, 255);
    display_cub_map(p, p->colors.floor, x, y, width);
    j = 0;
    while (j <= 2 * p->fps.rad)
    {
	    i = 0;
        while (i <= 2 * p->fps.rad)
        {
            dist = sqrt((i - p->fps.rad) * (i - p->fps.rad) + (j - p->fps.rad) * (j - p->fps.rad));
            if (dist > (p->fps.rad - 0.5) && dist < (p->fps.rad + 0.5))
            {    
                my_mlx_pixel_put(p, i+x, j+y, p->colors.person);		
               // line_dir(p, x, y, p->colors.person);
            }
            i++;
        }
        j++;
    }	
}

void    ft_move_player(t_param *p)
{
    p->fps.rot_angle += p->fps.dir_turn * p->fps.rot_speed;
    p->fps.move_step = p->fps.dir_walk * p->fps.move_speed;
    

}

/*void    get_view(int keycode, t_param *p)
{
    int i;
    int j;
    char temp;

    j = 0;
    while (j < p->map.mapY)
    {
	    i = 0;
	    while (i < p->map.line_max)
	    {
			if (ft_isview(p->map.tab[j][i]))
            {
                    temp = p->map.tab[j][i]; 
                    p->map.tab[j - 1][i] = temp;
            }
	        i++;
	    }
	    j++;
    }
}

void    player_move(int x, int y, int keycode, t_param *p)
{
    char temp;
    if (keycode == GO_UP)
    {
        get_view(x, y, keycode, p);
    }
    if (keycode == GO_DOWN)
    {
       temp = p->map.tab[y][x]; 
       p->map.tab[y + 1][x] = temp;
    } 
    if (keycode == GO_LEFT)
    {
       temp = p->map.tab[y][x]; 
       p->map.tab[y][x - 1] = temp;
    } 
    if (keycode == GO_RIGHT)
    {
       temp = p->map.tab[y][x]; 
       p->map.tab[y][x + 1] = temp;
    } 
}
*/