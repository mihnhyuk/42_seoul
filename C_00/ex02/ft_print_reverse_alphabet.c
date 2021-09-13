/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:18:26 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/11 19:41:39 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	*reverse_alphabet;

	reverse_alphabet = "zyxwvutsrqponmlkjihgfedcba";
	write(1, reverse_alphabet, 26);
}
