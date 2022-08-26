/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:43:37 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/25 23:57:31 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	pop_with_mutex(t_philo *p)
{
	int	id;

	pthread_mutex_lock((p->q));
	id = pop(p->waiting);
	pthread_mutex_unlock((p->q));
	while (id != -1 && p[id].state != 0 && p->state != 9)
	{
		if (check_done(p))
			return (id);
	}
	return (id);
}
