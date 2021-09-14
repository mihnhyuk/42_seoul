/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:22:31 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/15 02:01:59 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	ft_char_is_printable(char str)
{
	if ((str > 20) && (str < 127))
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	 int	idx;
	 int	to_hex;
	char	*translator = "0123456789abcdef";
	
	idx = -1;
	while(str[++idx])
	{
		if( ft_char_is_printable(str[idx]))
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

int main()
{
	char *ex = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(ex);
}
