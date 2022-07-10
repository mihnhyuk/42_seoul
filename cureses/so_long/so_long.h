/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:53:26 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/10 18:16:01 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "str_ary.h"
#define PIX 50

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

char		*ft_strdup(char *src);
t_strary	*read_map(const char *map_name);
int			input_check(t_strary *map);
int			check_error(t_strary *map);
void	    draw_map(t_strary *map);

#endif