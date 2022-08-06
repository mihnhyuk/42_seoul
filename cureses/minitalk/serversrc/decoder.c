/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:46:01 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/04 11:49:23 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	init_decoder(t_dynamicStr *s);
static void	bit_shifting(char *c, int *c_bit, unsigned char bit);

int	decoder(unsigned char bit)
{
	static char			c;
	static int			c_bit;
	static int			flag;
	static t_dynamicStr	s;

	if (flag == 0)
	{
		if (init_decoder(&s) == -1)
			return (-1);
		flag = 1;
	}
	bit_shifting(&c, &c_bit, bit);
	if (c_bit == 8)
	{
		if (c == 0)
		{
			ft_printf("%s\nProcess ID : %d\n", s.str, getpid());
			ft_free(s.str);
			flag = 0;
			c_bit = 0;
		}
		else if (!push_back(&s, c))
			return (-1);
	}
	return (0);
}

static int	init_decoder(t_dynamicStr *s)
{
	s->capacity = 10;
	s->length = 0;
	s->str = (char *)malloc(s->capacity * sizeof(char));
	if (s->str == NULL)
	{
		error_msg("Memory shortage");
		return (1);
	}
	return (0);
}

static void	bit_shifting(char *c, int *c_bit, unsigned char bit)
{
	int	idx;

	if (*c_bit > 7)
	{
		(*c_bit) = 0;
		(*c) = 0;
	}
	idx = -1;
	bit = (bit << (*c_bit));
	(*c) = ((*c) | bit);
	(*c_bit)++;
}
