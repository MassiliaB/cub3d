/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:23:16 by masboula          #+#    #+#             */
/*   Updated: 2021/02/24 16:23:22 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "structs.h"
# include "keys.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <math.h>

int				open_cub(t_param *p, char *path);
int				parse_error(t_param *p);
int				parse_cub(t_param *p, int fd, char *path);
int				parse_map(t_param *p, char *line);
int				get_no(char *line, t_param *p);
int				get_so(char *line, t_param *p);
int				get_we(char *line, t_param *p);
int				get_ea(char *line, t_param *p);
int				get_sprite(char *line, t_param *p);
int				is_there_num(char *line);
int				check_col(t_param *p);
int				ft_isview(char view, t_param *p);
void			my_tiny_map(t_param *p);
void			display_cub_map(t_param *p, int color, int x, int y);
int				get_f(char *line, t_param *p);
int				get_c(char *line, t_param *p);
int				get_r(char *line, t_param *p);
int				creat_trgb(int t, int r, int g, int b);
void			sprite_casting(t_param *p);
int				get_tex_path(t_param *p);
int				print_error(char *str);
int				creat_trgb(int t, int r, int g, int b);
int				quit(t_param *p, char *str, char *line);
void			init_img(t_param *p);
int				word_check(char *str, char *comp);
int				save(t_param *p);
int				mlx_exit(t_param *p);
int				ft_len(int num);
void			put_sprite_on(t_param *p);
void			put_tex_on(t_param *p, int x);
void			wall_dist(t_param *p);
void			wall_tex_value(t_param *p, int x);
char			*ft_cleandup(char *str, char *dst);
void			my_mlx_pixel_put(t_param *data, int x, int y, int color);
int				key_press(int keycode, t_param *p);
int				key_release(int keycode, t_param *p);
void			put_floorsky(t_param *p);
void			init_player(t_param *p);
int				get_update(t_param *p);
void			move(t_param *p);
void			stepx(t_param *p, int x);
void			ft_is_wall(t_param *p);
void			line_wall(t_param *p, int x);
void			choose_wall_dirns(t_param *p);
t_sprites_ptr	*get_sprites_pos(t_param *p, int i);

#endif
