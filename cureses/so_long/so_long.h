/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:53:26 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/29 01:40:23 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "str_ary.h"

char		*ft_strdup(char *src);
t_strary	*read_map(const char *map_name);
int			input_check(t_strary *map);
int			check_error(t_strary *map);

#endif