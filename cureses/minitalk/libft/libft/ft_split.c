/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:30:27 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/22 15:30:28 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	field_num(char const *str, char c);
static void	set_field_size(char const *str, char c, char **result);

char	**ft_split(char const *str, char c)
{
	char	**result;

	result = (char **)malloc((field_num(str, c) + 1) * sizeof (char *));
	if (result == NULL)
		return (NULL);
	set_field_size(str, c, result);
	return (result);
}

static void	set_field_size(char const *str, char c, char **result)
{
	int	var[4];

	var[0] = -1;
	var[1] = var[0];
	var[2] = 0;
	var[3] = 0;
	while (str[var[3]])
	{
		if (str[var[3]] != c)
		{
			if (var[3] == 0)
				var[0] = var[3];
			else if (str[var[3] - 1] == c)
				var[0] = var[3];
			if (!str[var[3] + 1] || str[var[3] + 1] == c)
			{
				var[1] = var[3];
				result[var[2]] = (char *)malloc((var[1] - var[0] + 2)
						* sizeof (char));
				ft_strlcpy(result[var[2]++], &str[var[0]], var[1] - var[0] + 2);
			}
		}
		var[3]++;
	}
	result[var[2]] = 0;
}

static int	field_num(char const *str, char c)
{
	int	idx;
	int	counter;

	idx = 0;
	counter = 0;
	while (str[idx])
	{
		if (str[idx] != c)
		{
			if (idx == 0)
				counter++;
			else if (str[idx - 1] == c)
				counter++;
		}
		idx++;
	}
	return (counter);
}
