/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:13:10 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/26 17:58:11 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo			*philo;
	struct timeval	tv;
	int				id;

	philo = (t_philo *)args;
	id = -1;
	gettimeofday(&tv, NULL);
	while (++id < philo->args->philos_n)
	{
		philo[id].t = tv;
		philo[id].state = 0;
	}
	while (1)
	{
		id = pop_with_mutex(philo);
		if (id != -1 && philo[id].state == 0)
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

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->forks[philo->first_fork]);
	gettimeofday(&t, NULL);
	if (philo->state == 1)
		printf("%dms philosopher %d has taken fork\n",
			to_ms(t), philo->id + 1);
	if (philo->args->philos_n == 1)
	{
		pthread_mutex_unlock(&philo->forks[philo->first_fork]);
		while (!check_done(philo))
			transaction(philo, 10, 9);
		return (NULL);
	}
	pthread_mutex_lock(&philo->forks[philo->second_fork]);
	gettimeofday(&t, NULL);
	if (philo->state == 1)
		printf("%dms philosopher %d has taken fork\n",
			to_ms(t), philo->id + 1);
	ft_eat(philo);
	transaction(philo, 8, 9);
	transaction(philo, 10, 9);
	return (NULL);
}

int	ft_eat(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	gettimeofday(&philo->t, NULL);
	if (philo->state == 1)
		printf("%dms philosopher %d is eating\n",
			to_ms(philo->t), philo->id + 1);
	ft_usleep(philo->args->time_to_sleep, philo->t);
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
	struct timeval	t;
	t_philo			*philo;

	philo = (t_philo *)args;
	gettimeofday(&t, NULL);
	if (philo->state == 1 || philo->state == 8)
		printf("%dms philosopher %d is sleeping\n",
			to_ms(t), philo->id + 1);
	ft_usleep(philo->args->time_to_sleep, t);
	ft_think((void *)philo);
}

void	ft_think(void *args)
{
	struct timeval	t;
	t_philo			*philo;

	philo = (t_philo *)args;
	gettimeofday(&t, NULL);
	if (philo->state == 1 || philo->state == 8)
		printf("%dms philosopher %d is thinking\n",
			to_ms(t), philo->id + 1);
	transaction(philo, 1, 0);
	return ;
}
