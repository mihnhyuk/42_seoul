/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:56:56 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/17 11:04:23 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
char	*ft_strstr(char *heystack, char *to_find);
char	*replace_str(char *starting_point, char *replace);
int	ft_strlen(char *str);

int	main(int argc, char *argv[])
{	
	char	*to_replace;

	if (argc != 4)
		write(1, "\n", 1);
	else
	{
		to_replace = ft_strstr(argv[1], argv[2]);
		if (!to_replace)
		{
			write(1, argv[1], ft_strlen(argv[1]));
			write(1, "\n", 1);
			return (0);
		}
		while (to_replace)
		{
			to_replace = replace_str(to_replace, argv[3]);
			to_replace = ft_strstr(to_replace, argv[2]);
		}
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, "\n", 1);
		return (0);
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*replace_str(char *starting_point, char *replace)
{
	int	idx;
	
	idx = 0;
	while (replace[idx])
	{
		*(starting_point + idx) = replace[idx];
		idx++;
	}
	return (starting_point + idx);
}


char	*ft_strstr(char *heystack, char *to_find)
{
	int	idx;
	int	begin;
	int	match;

	begin = 0;
	while (heystack[begin])
	{
		idx = 0;
		match = 1;
		while (to_find[idx] && heystack[begin + idx])
		{
			if (heystack[begin + idx] != to_find[idx])
			{
				match = 0;
				break;
			}
			idx++;
		}
		if (match)
			return (heystack + begin);
		begin++;
	}
	return (0);
}
