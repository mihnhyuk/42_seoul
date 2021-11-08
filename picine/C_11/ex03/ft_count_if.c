/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:44:59 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/29 20:10:07 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	idx;

	count = 0;
	idx = 0 ;
	while (idx < length)
	{
		if ((*f)(tab[idx]))
			count++;
		idx++;
	}
	return (count);
}
