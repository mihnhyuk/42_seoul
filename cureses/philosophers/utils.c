/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:43:37 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/04 12:13:19 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int input_check(int argc, char **argv, t_args *args)
{
	if (!(argc == 5 || argc == 6))
		return (error_msg("Argu err"));
	args->philos_n = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->eat_n = ft_atoi(argv[5]);
	else
		args = > eat_n = 0;
	if (args->philos_n > 1 && args->time_to_die > 0 && args->time_to_eat > 0
			&& args->time_to_sleep > 0 && args->eat_n >= 0)
		return (1);
	else
		return (0);
}

int init_table(t_args *args, t_table *table)
{
	int	idx;

	table->forks = (pthread_mutex_t *)malloc(args->philos_n * sizeof(pthread_mutex_t));
	table->pthread = (pthread_t *)malloc(args->philos_n * sizeof(pthread_t));
	if (table->forks == NULL || table->pthread == NULL)
	{
		error_msg("Memory shortage");
		exit(0);
	}
	idx = -1;
	while (++idx < args->philos_n)
	{
		pthread_mutex_init(table->forks[idx], NULL);
		pthread_ini
	}
}