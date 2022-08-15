/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:35:55 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/15 23:18:32 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_args
{
	int philos_n;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int eat_n;
}t_args;

typedef struct s_table
{
	pthread_mutex_t		*forks;
	pthread_t			*philos;
}t_table;

typedef struct s_philo
{
	int		id;
	int		state;
	t_args	*args;
	pthread_mutex_t		*forks;
	pthread_t			*philos;
	t_table	*table;
}t_philo;

int		input_check(int argc, char **argv, t_args *args);
int		init_table(t_args *args, t_table *table, t_philo *philos);
int		error_msg(char *msg);
void	*routine(void *args);
int		ft_atoi(const char *str);
float	getmillisec(struct timeval t);

#endif