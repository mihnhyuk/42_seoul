/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:15 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/29 19:21:16 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
# include <unistd.h>

void	plus_oper(int a, int b);
void	minus_oper(int a, int b);
void	multi_oper(int a, int b);
void	div_oper(int a, int b);
void	mod_oper(int a, int b);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
#endif
