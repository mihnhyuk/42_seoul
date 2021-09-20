/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:39:40 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 14:44:37 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{	
	argc = 0;
	while (argv[0][argc])
		write(1, &argv[0][argc++], 1);
	write(1, "\n", 1);
}
