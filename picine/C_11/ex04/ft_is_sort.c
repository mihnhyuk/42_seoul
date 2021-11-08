/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:43:40 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/29 20:10:26 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	j;
	int	flag1;
	int flag2;

	flag1 = 1;
	flag2 = 1;
	j = 0;
	while (j < length - 1)
	{
		if ((*f)(tab[j], tab[j + 1]) < 0)
			flag1 = 0;
		j++;
	}
	j = 0;
	while (j < length - 1)
	{
		if ((*f)(tab[j], tab[j + 1]) > 0)
			flag2 = 0;
		j++;
	}
	if (flag1 || flag2)
		return (1);
	return (0);
}
