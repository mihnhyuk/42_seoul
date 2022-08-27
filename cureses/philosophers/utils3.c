/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:10:13 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/27 19:06:59 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	getstate(t_philo *p)
{
	int	ret;

	pthread_mutex_lock(p->state_m);
	ret = p->state;
	pthread_mutex_unlock(p->state_m);
	return (ret);
}

void	print_m(struct timeval *t, t_philo *p, char *s)
{
	pthread_mutex_lock(&(p->q[1]));
	gettimeofday(t, NULL);
	printf("%dms philosopher %d %s\n", to_ms(*t), p->id + 1, s);
	pthread_mutex_unlock(&(p->q[1]));
}

void	start_mon(t_philo *philo, struct timeval tv)
{
	int	id;

	id = -1;
	while (++id < philo->args->philos_n)
	{
		pthread_mutex_lock(philo[id].state_m);
		philo[id].t = tv;
		philo[id].state = 0;
		pthread_mutex_unlock(philo[id].state_m);
	}
}
