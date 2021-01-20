#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "structs.h"
# include "keys.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <math.h>


int		creat_trgb(int t, int r, int g, int b);
int		print_error(char *str);
int		quit(t_param *params, char *str);
void	ft_init_img(t_param *p);
int		main_loop(t_param *p);
int		open_cub(t_param *p, char *path);
int		parse_map(t_param *p, char *line);
int		parse_no_error(t_param *p, int fd, char *path);
int		get_elements(char *line, t_param *p);
int		get_tab(char *line, t_param *p);
void    my_mlx_pixel_put(t_param *data, int x, int y, int color);
void	my_cub_map(t_param *p);
int		is_there_num(char *line);
int	    get_good_line(char *line, t_param *p, int x);
int		ft_isview(char view, t_param *p);
int		malloc_lines(t_param *p, char *line, int fd);
int     get_f(char *line, t_param *p);
int     get_c(char *line, t_param *p);
int     get_r(char *line, t_param *p);
int	    check_col(t_param *p);
int	    check_line(t_param *p, int y, int x);
void	init_player_map(t_param *p, int x, int y);
void	display_circle_map(t_param *p, int x, int y, int width);
void	line_dir(t_param *p, int x, int y, int color);
int     key_press(int keycode, t_param *p);
int     key_release(int keycode, t_param *p);
void	display_cub_map(t_param *p, int color, int x, int y, int width);
void     put_floorsky(t_param *p);
void    player_move(int x, int y, int keycode, t_param *p);
void    get_view(int keycode, t_param *p);
void    raycasting(t_param *p);
void	set_camsn(char view, t_param *p);
void	set_camwe(char view, t_param *p);
void	init_player(t_param *p);
int    update_scene(t_param *p);
int    get_update(t_param *p);
int     moving_ok(char pos);
void    rotate(t_param *p);
int    move(t_param *p);
void    stepX(t_param *p, int x);
void    stepY(t_param *p);
void    ft_is_wall(t_param *p);
void    wall_dist(t_param *p);
void    line_wall(t_param *p, int x);
void    draw_verline(int x, t_param *p, int color);

#endif
