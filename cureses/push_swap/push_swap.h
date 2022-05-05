/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:36:17 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/05 20:13:09 by minhjang         ###   ########.fr       */
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
void	ft_putnbr_fd(int n, int fd);
t_list	*new_node(void);
void	print_stack(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *a, t_stack *b);
void    sort(t_stack *a, t_stack *b);

#endif