/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:43:37 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/25 18:11:19 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_fork(t_philo *philo, t_args *args, int idx);

int	error_msg(char *msg)
{
	printf("%s\n", msg);
	return (0);
}

int	input_check(int argc, char **argv, t_args *args)
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

int	init_table(t_args *args, t_philo **philos, t_queue *que)
{
	int				idx;
	pthread_mutex_t	*fork;

	fork = (pthread_mutex_t *)malloc(args->philos_n * sizeof(pthread_mutex_t));
	*philos = (t_philo *)malloc(args->philos_n * sizeof(t_philo));
	(*philos)->q = (pthread_mutex_t *)malloc(3 * sizeof(pthread_mutex_t));
	(*philos)->state_m = (pthread_mutex_t *)
		malloc(args->philos_n * sizeof(pthread_mutex_t));
	(*philos)->dl = (int *)malloc(sizeof(int));
	if (fork == NULL || *philos == NULL || (*philos)->q == NULL
		|| (*philos)->state_m == NULL || (*philos)->dl == NULL)
	{
		error_msg("Memory shortage");
		return (0);
	}
	init_mutex(args, philos, que, fork);
	return (0);
}

static int	set_fork(t_philo *philos, t_args *args, int idx)
{
	philos[idx].id = idx;
	philos[idx].state = 0;
	philos[idx].eat_n = 0;
	philos[idx].args = args;
	philos[idx].q = philos[0].q;
	philos[idx].dl = philos[0].dl;
	if (idx == 0)
	{
		philos[idx].left_fork = philos->args->philos_n - 1;
		philos[idx].right_fork = 0;
		idx = -1;
		while (++idx < args->philos_n)
			philos[idx].state_m = &(philos[0].state_m[idx]);
	}
	else
	{
		philos[idx].left_fork = idx - 1;
		philos[idx].right_fork = idx;
	}
	return (0);
}

void	*free_all(t_philo *philos)
{
	int	idx;

	idx = -1;
	while (++idx < philos->args->philos_n)
	{
		pthread_mutex_destroy(&(philos->forks[idx]));
		pthread_mutex_destroy(&(philos->state_m[idx]));
	}
	pthread_mutex_destroy(&(philos->q[2]));
	pthread_mutex_destroy(&(philos->q[1]));
	pthread_mutex_destroy(&(philos->q[0]));
	free(philos->dl);
	free(philos->waiting->que);
	free(philos->q);
	free(philos->forks);
	free(philos);
	return (NULL);
}
