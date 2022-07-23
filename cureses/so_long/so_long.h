/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:53:26 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/23 11:04:19 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"

# define PIX	32
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53
# define KEYPRESSMASK 2
# define EXITC	0x00FFFFFF
# define WALLC	0x00FF6699
# define COLLECTALBEC	0x00336699
# define PLAYERC	0x0000FF00
# define EMPTYC		0x00000000

typedef struct s_strary
{
	char **ary;
	int	capacity;
	int	size;
	int	width;
	int	x;
	int	y;
	int	movements;
	int	coin_num;
	int	**coll_pos;
}	t_strary;

typedef struct s_imgs
{
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
}			t_imgs;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_strary	*map;
	t_imgs		*img;
}				t_vars;


void		*init_strs(t_strary *strs, int size);
void		*push_string(t_strary *strs, char *str);
t_strary	*copy_strs(t_strary *org);
void		*free_strs(t_strary *strs, int size);
void		*free_cont(t_strary *strs);
void		*free_coll(t_strary *map, int size);
char		*ft_strdup(char *src);
void		ft_putnbr_fd(int n, int fd);
t_strary	*read_map(const char *map_name);
int			input_check(t_strary *map);
int			check_error(t_strary *map);
void		draw_map(t_strary *map);
int			key_hook(int keycode, t_vars *vars);
void		img_put(t_vars *vars, int x, int y, void *imgs);
void		pixel_put(t_vars *vars, int x, int y, int color);
void		draw_player(t_vars *vars, int x, int y);
void		draw_empty(t_vars *vars, int x, int y);
void		left(t_vars *vars);
void		right(t_vars *vars);
void		up(t_vars *vars);
void		down(t_vars *vars);
int			end_game(t_vars *vars);
void		check_event(t_vars *vars, int x, int y);
void		get_asset(t_vars *var, t_imgs *imgs);
void		*print_err(t_strary *map, t_strary *copy);
int			map_name_check(char *arg, t_strary **map);
int			map_size_check(t_strary *map);
int			line_too_long(t_strary *map, int w, int h, int *ecp);
int			cw(t_strary *map, int w, int h, int *ecp);

#endif