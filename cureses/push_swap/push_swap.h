/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:36:17 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/04 20:29:32 by minhjang         ###   ########.fr       */
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

typedef struct s_result
{
	int	top;
	int	capacity;
	int	*used_inst;
}	t_result;

void	swap(t_stack *s);
void	push(t_stack *s, int data);
int		pop(t_stack *s);
int		peek(t_stack *s);
void	init_stack(t_stack *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
t_list	*new_node(void);
void	print_stack(t_stack *a, t_stack *b);
void	sa(t_stack *a, t_result *result);
void	sb(t_stack *b, t_result *result);
void	ss(t_stack *a, t_stack *b, t_result *result);
void	pa(t_stack *a, t_stack *b, t_result *result);
void	pb(t_stack *b, t_stack *a, t_result *result);
void	ra(t_stack *s, t_result *result);
void	rb(t_stack *s, t_result *result);
void	rr(t_stack *a, t_stack *b, t_result *result);
void	rra(t_stack *s, t_result *result);
void	rrb(t_stack *s, t_result *result);
void	rrr(t_stack *a, t_stack *b, t_result *result);
void	init_result(t_result *result, char *result_map[]);
void	push_result(t_result *result, int data);
void	sort(t_stack *a, t_stack *b, t_result *r);
int		find_pivot(t_stack *a, int range);
int		is_aligned(t_stack *s, int range);
int		input_check(int argc, char **argv);
int		many_args(char **argv, int idx, t_stack *a);
void 	one_arg(char *s, t_stack *a);
int		dup_check(t_stack *a);
void	three(t_stack *a, t_result * r);
void	btoa_opt(t_stack *a, t_stack *b, t_result *r, int range);
int		is_reversed(t_stack *b, int range);
int		atob_opt(t_stack *a, t_result *r, int range);

#endif