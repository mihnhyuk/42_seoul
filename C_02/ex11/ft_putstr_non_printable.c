/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:22:31 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/15 21:09:45 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_char_is_non_printable(char str)
{
	if ((str >= 32) && (str < 127))
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	       int	idx;
	       int	to_hex;
	const char	*translator = "0123456789abcdef";

	idx = -1;
	while (str[++idx])
	{
		if (ft_char_is_non_printable(str[idx]))
		{
			to_hex = str[idx];
			write(1, "\\", 1);
			write(1, translator + (to_hex / 16), 1);
			write(1, translator + (to_hex % 16), 1);
		}
		else
			write(1, &str[idx], 1);
	}
}
