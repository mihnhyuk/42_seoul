/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:22:31 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/16 13:45:26 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_char_is_non_printable(unsigned char str)
{
	if ((str >= 32) && (str < 127))
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	          int	idx;
	   const char	*translator = "0123456789abcdef";
	unsigned char	u_chr;

	idx = -1;
	while (str[++idx])
	{
		u_chr = (unsigned char)str[idx];
		if (ft_char_is_non_printable(u_chr))
		{
			write(1, "\\", 1);
			write(1, translator + (u_chr / 16), 1);
			write(1, translator + (u_chr % 16), 1);
		}
		else
			write(1, &str[idx], 1);
	}
}
