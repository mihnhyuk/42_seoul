/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:57:45 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/29 18:57:47 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	main(int argc, char *argv[])
{
	void	(*fp[5])(int, int);

	fp[0] = plus_oper;
	fp[1] = minus_oper;
	fp[2] = multi_oper;
	fp[3] = div_oper;
	fp[4] = mod_oper;
	if (argc != 4)
		return (0);
	if (*argv[2] == '+')
		fp[0](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (*argv[2] == '-')
		fp[1](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (*argv[2] == '*')
		fp[2](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (*argv[2] == '/')
		fp[3](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (*argv[2] == '%')
		fp[4](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
