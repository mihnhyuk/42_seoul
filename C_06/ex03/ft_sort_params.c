/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:03:44 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 21:57:08 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2);
void	sort(char *str[], int num);
void	swap(char **s1, char **s2);

int	main(int argc, char *argv[])
{
	int	iter;
	int	str_iter;

	sort(++argv, argc - 1);
	iter = 0;
	while (iter < argc - 1)
	{
		str_iter = 0;
		while (argv[iter][str_iter])
		{
			write(1, &argv[iter][str_iter], 1);
			str_iter++;
		}
		write(1, "\n", 1);
		iter++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] == s2[idx])
			idx++;
		else
			return (s1[idx] - s2[idx]);
	}
	return (s1[idx] - s2[idx]);
}

void	sort(char *str[], int num)
{
	int	iter;

	while (num > 1)
	{
		iter = 0;
		while (iter < num - 1)
		{
			if (ft_strcmp(str[iter], str[iter + 1]) > 0)
				swap(&str[iter], &str[iter + 1]);
			iter++;
		}
		num--;
	}
}

void	swap(char **s1, char **s2)
{
	char	*tmp;
	
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
