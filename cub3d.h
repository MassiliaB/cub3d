#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "structs.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

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
void            my_mlx_pixel_put(t_param *data, int x, int y, int color);
void	my_cub_map(t_param *p);
int		is_there_num(char *line);
int	 get_good_line(char *line, t_param *p, int x);
int		ft_isview(char view);
int		malloc_lines(t_param *p, char *line, int fd);
int	get_f(char *line, t_param *p);
int	get_c(char *line, t_param *p);
int	get_r(char *line, t_param *p);
int	check_col(t_param *p);
int	check_line(t_param *p, int y, int x);

#endif
