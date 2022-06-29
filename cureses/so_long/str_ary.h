/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ary.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:41:35 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/29 16:23:32 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_ARY_H
# define STR_ARY_H

typedef struct s_strary
{
	char **ary;
	int	capacity;
	int	size;
	int	width;
}	t_strary;

void		*init_strs(t_strary *strs, int size);
void		*push_string(t_strary *strs, char *str);
t_strary	*copy_strs(t_strary *org);
void		*free_strs(t_strary *strs, int size);
void		*free_cont(t_strary *strs);

#endif