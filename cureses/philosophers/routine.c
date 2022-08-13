/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:13:10 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/13 15:25:14 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

void	*routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	
	ft_try(philo);

	return (NULL);
}

void	ft_try(t_philo *philo)
{
	struct timeval t;
	
	pthread_mutex_lock(philo->table->forks[philo->left_fork]);
	gettimeofday(&t, NULL);
	printf("%0.8dms philosopher %d has taken fork\n", t.tv_usec / 1000, philo->id + 1);
	pthread_mutex_lock(philo->table->forks[philo->right_fork]);
	gettimeofday(&t, NULL);
	printf("%0.8dms philosopher %d has taken fork\n", t.tv_usec / 1000, philo->id + 1);
	ft_eat(philo);
}

int ft_eat(t_philo *philo)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	printf("%dms philosopher %d is eating\n", t.tv_usec / 1000, philo->id + 1);
	pthread_mutex_unlock(philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(philo->table->forks[philo->right_fork]);
	usleep(1000 * philo->args->time_to_eat);
	ft_sleep(philo);
	return (1);
}

void ft_sleep(t_philo *philo)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	printf("%0.8dms philosopher  %d is sleeping\n", t.tv_usec / 1000, philo->id + 1);
	usleep(1000 * philo->args->time_to_sleep);
	ft_think(philo);
}

void ft_think(t_philo *philo)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	printf("%0.8dms philosopher  %d is thinking\n", t.tv_usec / 1000, philo->id + 1);

}
