/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:38:14 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/25 18:20:43 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_fork(t_philo *philos, t_args *args, int idx);

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

void	init_mutex(t_args *args, t_philo **philos,
			t_queue *que, pthread_mutex_t *fork)
{
	int	idx;

	*((*philos)->dl) = 0;
	pthread_mutex_init(&((*philos)->q[0]), NULL);
	pthread_mutex_init(&((*philos)->q[1]), NULL);
	pthread_mutex_init(&((*philos)->q[2]), NULL);
	idx = -1;
	while (++idx < args->philos_n)
	{
		pthread_mutex_init(&fork[idx], NULL);
		pthread_mutex_init(&((*philos)->state_m[idx]), NULL);
	}	
	idx = -1;
	while (++idx < args->philos_n)
	{
		(*philos)[idx].forks = fork;
		(*philos)[idx].waiting = que;
		set_fork(*philos, args, idx);
	}
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
