/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:04:12 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/23 21:45:17 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				check_deli(char c, char *charset);
int				field_num(char *str, char *charset);
void			set_field_size(char *str, char *charset, char **result);

char	**ft_split(char *str, char *charset)
{
	char	**result;

	if (field_num(str, charset) == 0)
	{
		result = (char **)malloc(sizeof (char *));
		result[0] = 0;
		return (result);
	}
	result = (char **)malloc(field_num(str, charset) * sizeof (char *));
	if (result == NULL)
		return (NULL);
	set_field_size(str, charset, result);
	return (result);
}

void	set_field_size(char *str, char *charset, char **result)
{
	int	idx;
	int	start;
	int	finish;
	int	r_idx;

	start = 0;
	finish = start;
	r_idx = 0;
	idx = 1;
	while (str[idx])
	{
		if ((!check_deli(str[idx], charset))
			&& check_deli(str[idx - 1], charset) && start == finish)
			start = idx;
		else if (start != -1 && check_deli(str[idx], charset)
			&& start != finish)
		{
			finish = idx;
			result[r_idx] = (char *)malloc((finish - start + 1)
					* sizeof (char));
			ft_strlcpy(result[r_idx++], &str[start], finish - start + 1);
			start = finish;
		}
		idx++;
	}
}

int	field_num(char *str, char *charset)
{
	int	idx;
	int	counter;

	idx = 0;
	counter = 0;
	while (str[idx])
	{
		if (check_deli(str[idx], charset))
		{
			if (idx == 0)
				counter++;
			else if (!check_deli(str[idx - 1], charset))
				counter++;
		}
		idx++;
	}
	return (counter);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	if (size == 0 )
	{
		while (src[idx])
			idx++;
		return (idx);
	}
	while ((idx < size - 1) && src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	while (src[idx])
		idx++;
	return (idx);
}

int	check_deli(char c, char *charset)
{
	int	idx;

	idx = 0;
	while (charset[idx])
	{
		if (c == charset[idx])
			return (1);
		idx++;
	}
	return (0);
}
