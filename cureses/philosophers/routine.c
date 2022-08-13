/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:13:10 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/11 22:17:03 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

void	*routine(void *args)
{
	t_philo *philo;
	// int end;

	philo = (t_philo *)args;
	// end = 0;
	if (philo->state == 0)
		ft_eat(philo);
	else if (philo->state == 1)
		ft_sleep(philo);
	else if (philo->state == 2)
		ft_think(philo);

	// if (end == 1)
	return (NULL);
}

int ft_eat(t_philo *philo)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	printf("%f %d is eating\n", getmillisec(t), philo->id + 1);
	usleep(1000 * philo->args->time_to_eat);

	return (1);
}

void ft_sleep(t_philo *philo)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	printf("%0.8f %d is sleeping\n", getmillisec(t), philo->id + 1);
	usleep(1000 * philo->args->time_to_sleep);
}

void ft_think(t_philo *philo)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	printf("%0.8f %d is thinking\n", getmillisec(t), philo->id + 1);
}
