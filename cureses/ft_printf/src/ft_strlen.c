/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:55:12 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/25 15:47:25 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
		iter++;
	return (iter);
}
