/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:01:53 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/29 20:11:26 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char*))
{
	 int	i;
	 int	j;
	char	*tmp;

	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[j + 1] != 0)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
