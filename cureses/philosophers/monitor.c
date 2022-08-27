/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:57:48 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/27 18:59:06 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	you_died(t_philo *p);

int	dead_monitor(t_philo *philos)
{
	int				idx;
	int				state;
	struct timeval	cur_t;

	while (1)
	{
		idx = -1;
		gettimeofday(&cur_t, NULL);
		while (++idx < philos->args->philos_n)
		{
			state = getstate(&philos[idx]);
			if (state != -1 && state != 8 && state != 9
				&& (time_diff(to_ms(cur_t), to_ms(philos[idx].t))
					> philos->args->time_to_die))
			{
				you_died(philos);
				print_m(&cur_t, &philos[idx], "is died");
				return (0);
			}
		}
		if (check_done(philos))
			break ;
		usleep(800);
	}
	return (0);
}

int	check_done(t_philo *philo)
{
	int	idx;

	idx = -1;
	while (++idx < philo->args->philos_n)
	{
		if (getstate(&philo[idx]) != 9)
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
		pthread_mutex_lock(p[idx].state_m);
		if (p[idx].state != 0 && p[idx].state != 8)
			p[idx].state = 10;
		else
			p[idx].state = 9;
		pthread_mutex_unlock(p[idx].state_m);
	}
}

void	transaction(t_philo *p, int prev, int cur)
{
	pthread_mutex_lock(p->state_m);
	if (p->state == prev)
	{
		p->state = cur;
	}
	pthread_mutex_unlock(p->state_m);
}

void	even_odd(int *que, int size, int idx)
{
	if (size % 2 == 0)
	{
		while (++idx < size)
		{
			if (idx < size / 2)
				que[idx] = idx * 2;
			else
				que[idx] = (idx - (size / 2)) * 2 + 1;
		}
	}
	else
	{
		while (++idx < size)
		{
			if (idx <= size / 2)
				que[idx] = idx * 2;
			else
				que[idx] = (idx - (size / 2)) * 2 - 1;
		}
	}
}
