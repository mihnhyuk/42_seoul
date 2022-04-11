/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:36:17 by minhjang          #+#    #+#             */
/*   Updated: 2022/04/11 14:52:15 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	top;
	int	capacity;
	int	*ary;
}	t_stack;

typedef struct s_list
{
	struct s_list	*next;
	int				idx;
	char			*inst;
}	t_list;

void	swap(t_stack *s);
void	push(t_stack *s, int data);
int		pop(t_stack *s);
int		peek(t_stack *s);
void	init_stack(t_stack *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
t_list  *new_node();

#endif