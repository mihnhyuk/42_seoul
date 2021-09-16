/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:45:37 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/16 17:56:09 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;
	int	is_word;

	is_word = 1;
	idx = 0;
	while (str[idx])
	{
		if (is_word)
		{
			is_word = 0;
			if (str[idx] >= 'a' && str[idx] <= 'z')
				str[idx] += ('A' - 'a');
		}
		else if (str[idx] >= 'A' && str[idx] <= 'Z')
			str[idx] += ('a' - 'A');
		if (!is_alpha(str[idx]))
			is_word = 1;
		idx++;
	}
	return (str);
}
