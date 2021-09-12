/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:35:03 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/11 21:00:00 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_negative(int n)
{
	char	n_num;
	char	p_num;

	n_num = 'N';
	p_num = 'P';
	if (n >= 0)
		write(1, &p_num, 1);
	else
		write(1, &n_num, 1);
}
