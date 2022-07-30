/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:46:01 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/30 19:32:49 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	init_decoder(t_dynamicStr *s);
static void bit_shifting(char *c, int *c_bit, unsigned char bit);

void	decoder(unsigned char bit)
{
	static char			c;
	static int			c_bit;
	static int			flag;
	static t_dynamicStr	s;

	if (flag == 0)
	{
		init_decoder(&s);
		flag = 1;
	}
	bit_shifting(&c, &c_bit, bit);
    if (c_bit == 8)
	{
		if (c == 0)
		{
			ft_printf("%s\n", s.str);
			free(s.str);
			flag = 0;
		}
		if (!push_back(&s, c))
			exit(0);
	}
}

static void	init_decoder(t_dynamicStr *s)
{
	s->capacity = 10;
	s->length = 0;
	s->str = (char *)malloc(s->capacity * sizeof(char));
	if (s->str == NULL)
	{
		error_msg("Memory shortage");
		exit(0);
	}
}

static void bit_shifting(char *c, int *c_bit, unsigned char bit)
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
