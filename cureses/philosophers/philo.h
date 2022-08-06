/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:35:55 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/04 11:53:55 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./libft/includes/ft_printf.h"
# include "./libft/libft/libft.h"
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

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
	pthread_t pthread	*philos;
}t_table;

int input_check(int argc, char **argv);
int init_table(t_args *args, t_table *table);

#endif