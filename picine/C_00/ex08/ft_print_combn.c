/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang  <minhjang@student.42seoul.k      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:22:44 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/14 08:22:44 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:39:11 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/12 21:36:39 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

char	*out;

void	ft_put_str(char *str, int length)
{
	write(1, str, length);
}

void	str_cpy(char *obj, char * orig, int str_length)
{
	int	idx;

	idx = 0;
	while (idx < str_length)
		obj[idx] = orig[idx];
}

void	combn_recur(int num_digit, char *pre, int depth)
{
	char	cur[20];
	 int	last_idx;
	char	next_num;

	last_idx = depth - 1;

	if (num_digit == depth)
	{
		while (pre[last_idx] < 58)
		{
			pre[last_idx]++;
			ft_put_str(pre, depth);
		}
	}
	else
	{
		next_num = cur[depth - 1];
		str_cpy(cur, pre, depth);
		while (next_num < 57 - num_digit + depth)
		{
			next_num++;
			cur[depth] = next_num;
			combn_recur(num_digit, cur, depth + 1);
		}
		
	}
}
void	ft_print_combn(int n)
{
	combn_recur(n, "0", 1);
}

int main(){
	ft_print_combn(2);
}
