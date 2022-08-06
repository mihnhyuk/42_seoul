/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:13:10 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/06 15:35:53 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	if (philo->state == 0)
		eat(philo);
	else if (philo->state == 1)
		sleep(philo);
	else if (philo->state == 2)
		think(philo);
}

void eat(t_philo *philo)
{
	printf("eating\n");
	usleep(1);
}

void sleep(t_philo *philo)
{
	printf("sleeping\n");
	usleep(1);
}

void think(t_philo *philo)
{
	printf("time, \n")
	usleep(1);
}
