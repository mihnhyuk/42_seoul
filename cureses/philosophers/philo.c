/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:34:05 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/04 11:58:26 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int sit_at_table(t_args *args, t_table *table);

int main(int argc, char **argv)
{
	t_args args;
	t_table table;

	input_check(argc, argv, &args);
	init_table(&args, &table);
	sit_at_table(&args, &table)
}

static int sit_at_table(t_args *args, t_table *table)
{
	
}
