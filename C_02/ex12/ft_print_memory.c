/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:26:54 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/16 19:10:16 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	print_address_in_hex(char *addr);
void	print_str_to_hex(char *str, unsigned int size);
void	ft_putstr_non_printable(char *str, unsigned int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*dividor;

	dividor = (char *) addr;
	while (size > 16)
	{
		print_address_in_hex(dividor);
		print_str_to_hex(dividor, size);
		ft_putstr_non_printable(dividor, size);
		write(1, "\n", 1);
		size -= 16;
		dividor += 16;
	}
	print_address_in_hex(dividor);
	print_str_to_hex(dividor, size);
	ft_putstr_non_printable(dividor, size);
	write(1, "\n", 1);
	return (addr);
}

void	ft_putstr_non_printable(char *str, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < 16)
	{	
		if (idx >= size)
			break ;
		if (!((str[idx] >= 32) && (str[idx] < 127)))
			write(1, ".", 1);
		else
			write(1, &str[idx], 1);
		idx++;
	}
}

void	print_str_to_hex(char *str, unsigned int size)
{
	   const char	*hex_list = "0123456789abcdef";
	 unsigned int	idx;
	unsigned char	u_char;

	idx = 0;
	while (idx < 16)
	{
		u_char = (unsigned char) str[idx];
		if (idx >= size)
			write(1, "  ", 2);
		else
		{
			write(1, hex_list + (u_char / 16), 1);
			write(1, hex_list + (u_char % 16), 1);
		}
		if (idx % 2 == 1)
			write(1, " ", 1);
		idx++;
	}
}

void	print_address_in_hex(char *addr)
{
	unsigned long long int	p_to_i;
	            const char	*hex_list = "0123456789abcdef";
	                  char	hex[17];
	                   int	idx;

	idx = 0;
	while (idx < 16)
		hex[idx++] = 0;
	hex[idx] = '\0';
	p_to_i = (unsigned long long int)addr;
	while (idx >= 0)
	{
		hex[--idx] = *(hex_list + (p_to_i % 16));
		p_to_i /= 16;
	}
	write(1, hex, 16);
	write(1, ": ", 1);
}
