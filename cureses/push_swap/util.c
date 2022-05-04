/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:42:23 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/04 16:08:57 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*new_node(void)
{
	t_list		*n;
	static int	idx;

	n = (t_list *)malloc(sizeof(t_list));
	n->next = 0;
	n->idx = idx;
	idx++;
	return (n);
}
