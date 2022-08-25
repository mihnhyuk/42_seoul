/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:57:48 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/25 18:20:07 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	you_died(t_philo *p);

int	dead_monitor(t_philo *philos)
{
	int				idx;
	struct timeval	cur_t;	

	while (1)
	{
		idx = -1;
		gettimeofday(&cur_t, NULL);
		while (++idx < philos->args->philos_n)
		{
			if (philos[idx].state != 0 && philos[idx].state != 8
				&& philos[idx].state != 9 && ((cur_t.tv_usec / 1000)
					- (philos[idx].t.tv_usec / 1000)
					> philos->args->time_to_die))
			{
				you_died(philos);
				printf("%dms philosopher %d is died\n",
					cur_t.tv_usec / 1000, idx + 1);
				return (0);
			}
		}
		if (check_done(philos))
			break ;
	}
	return (0);
}

int	check_done(t_philo *philo)
{
	int				idx;
	struct timeval	t;

	idx = -1;
	while (++idx < philo->args->philos_n)
	{
		if (philo[idx].state != 9)
			return (0);
	}
	return (1);
}

static void	you_died(t_philo *p)
{
	int	idx;

	idx = -1;
	while (++idx < p->args->philos_n)
	{
		pthread_mutex_lock(p->state_m);
		if (p[idx].state != 0 && p[idx].state != 8)
			p[idx].state = 10;
		else
			p[idx].state = 9;
		pthread_mutex_unlock(p->state_m);
	}
}

void	transaction(t_philo *p, int prev, int cur)
{
	pthread_mutex_lock(p->state_m);
	if (p->state == prev)
		p->state = cur;
	pthread_mutex_unlock(p->state_m);
}

void	deadlock_shield(t_philo *p, int pv)
{
	if (pv == 0)
	{
		pthread_mutex_lock(&(p->q[1]));
		*(p->dl) += 1;
		if (*(p->dl) == p->args->philos_n - 1)
			pthread_mutex_lock(&(p->q[2]));
		pthread_mutex_unlock(&(p->q[1]));
	}
	else if (pv == 1)
	{
		pthread_mutex_lock(&(p->q[1]));
		if (*(p->dl) == p->args->philos_n - 1)
			pthread_mutex_unlock(&(p->q[2]));
		*(p->dl) -= 1;
		pthread_mutex_unlock(&(p->q[1]));
	}
}
