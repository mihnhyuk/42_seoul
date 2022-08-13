/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:43:37 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/13 15:27:09 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_fork(t_philo *philo);

int	error_msg(char *msg)
{
	printf("%s\n", msg);
	return (0);
}

int input_check(int argc, char **argv, t_args *args)
{
	if (!(argc == 5 || argc == 6))
		return (error_msg("Argu error"));
	args->philos_n = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->eat_n = ft_atoi(argv[5]);
	else
		args->eat_n = 0;
	if (args->philos_n > 1 && args->time_to_die > 0 && args->time_to_eat > 0
			&& args->time_to_sleep > 0 && args->eat_n >= 0)
		return (1);
	else
		return (0);
}

int init_table(t_args *args, t_table *table, t_philo *philos)
{
	int	idx;

	table->forks = (pthread_mutex_t *)malloc(args->philos_n * sizeof(pthread_mutex_t));
	table->philos = (pthread_t *)malloc(args->philos_n * sizeof(pthread_t));
	if (table->forks == NULL || table->philos == NULL)
	{
		error_msg("Memory shortage");
		exit(0);
	}
	idx = -1;
	while (++idx < args->philos_n)
		pthread_mutex_init(&table->forks[idx], NULL);
	idx = -1;
	philos->args = args;
	philos->table = table;
	while (++idx < args->philos_n)
	{
		philos->id = idx;
		philos->state = 0;
		set_fork(&philos);
		pthread_create(&table->philos[idx], NULL, routine, (void *)philos);
	}
	return (0);
}

static void	set_fork(t_philo *philo)
{
	if (philo->id == 0)
	{
		philo->left_fork = philo->args->philos_n - 1;
		philo->right_fork = 0;
	}
	else
	{
		philo->left_fork = philo->id - 1;
		philo->right_fork = philo->id;
	}
}