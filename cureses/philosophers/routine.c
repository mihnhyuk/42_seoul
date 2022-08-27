/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:13:10 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/27 19:07:44 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo			*philo;
	struct timeval	tv;
	int				id;

	philo = (t_philo *)args;
	gettimeofday(&tv, NULL);
	start_mon(philo, tv);
	while (1)
	{
		id = pop_with_mutex(philo);
		if (id != -1 && getstate(&philo[id]) == 0)
		{
			transaction(&philo[id], 0, 1);
			pthread_create(&(philo[id].philos),
				NULL, ft_try, (void *)(&philo[id]));
			pthread_detach(philo[id].philos);
		}
		if (check_done(philo))
			return (NULL);
	}
}

void	*ft_try(void *args)
{	
	t_philo			*philo;
	struct timeval	t;

	gettimeofday(&t, NULL);
	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->forks[philo->first_fork]);
	if (getstate(philo) == 1)
		print_m(&t, philo, "is has takn fork");
	if (philo->args->philos_n == 1)
	{
		pthread_mutex_unlock(&philo->forks[philo->first_fork]);
		while (!check_done(philo))
			transaction(philo, 10, 9);
		return (NULL);
	}
	pthread_mutex_lock(&philo->forks[philo->second_fork]);
	if (getstate(philo) == 1)
		print_m(&t, philo, "has taken fork");
	ft_eat(philo);
	transaction(philo, 8, 9);
	transaction(philo, 10, 9);
	return (NULL);
}

int	ft_eat(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->q[1]);
	gettimeofday(&philo->t, NULL);
	if (getstate(philo) == 1)
		printf("%dms philosopher %d is eating\n",
			to_ms(philo->t), philo->id + 1);
	pthread_mutex_unlock(&philo->q[1]);
	ft_usleep(philo->args->time_to_eat, philo->t);
	philo->eat_n++;
	if (philo->eat_n == philo->args->eat_n)
		transaction(philo, 1, 8);
	else
	{
		pthread_mutex_lock((philo->q));
		insert(philo->waiting, philo->id);
		pthread_mutex_unlock((philo->q));
	}
	pthread_mutex_unlock(&philo->forks[philo->first_fork]);
	pthread_mutex_unlock(&philo->forks[philo->second_fork]);
	ft_sleep((void *)philo);
	return (1);
}

void	ft_sleep(void *args)
{
	t_philo			*philo;
	struct timeval	t;

	philo = (t_philo *)args;
	gettimeofday(&t, NULL);
	if (getstate(philo) == 1 || getstate(philo) == 8)
		print_m(&t, philo, "is sleeping");
	ft_usleep(philo->args->time_to_sleep, t);
	ft_think((void *)philo);
}

void	ft_think(void *args)
{
	t_philo			*philo;
	struct timeval	t;

	philo = (t_philo *)args;
	gettimeofday(&t, NULL);
	if (getstate(philo) == 1 || getstate(philo) == 8)
		print_m(&t, philo, "is thinking");
	transaction(philo, 1, 0);
	return ;
}
