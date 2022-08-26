/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:35:55 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/25 21:26:54 by minhjang         ###   ########.fr       */
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
	int	philos_n;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_n;
}t_args;

typedef struct s_queue
{
	int	size;
	int	capacity;
	int	head;
	int	tail;
	int	*que;
}t_queue;

typedef struct s_philo
{
	int					id;
	int					state;
	int					eat_n;
	int					left_fork;
	int					right_fork;
	int					*dl;
	struct timeval		t;
	t_args				*args;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*state_m;
	pthread_mutex_t		*q;
	pthread_t			philos;
	t_queue				*waiting;
}t_philo;

int			input_check(int argc, char **argv, t_args *args);
int			init_table(t_args *args, t_philo **philos, t_queue *que);
int			error_msg(char *msg);
void		*routine(void *args);
int			ft_atoi(const char *str);
int			dead_monitor(t_philo *philos);
int			check_done(t_philo *philo);
int			init_queue(t_queue *que, int size);
int			insert(t_queue *que, int data);
int			pop(t_queue *que);
void		*ft_try(void *args);
int			ft_eat(void *args);
void		ft_sleep(void *args);
void		ft_think(void *args);
void		print_que(t_queue *que);
int			pop_with_mutex(t_philo *p);
void		*free_all(t_philo *philos);
void		transaction(t_philo *p, int prev, int cur);
void		deadlock_shield(t_philo *p, int pv);
void		init_mutex(t_args *args, t_philo **philos,
				t_queue *que, pthread_mutex_t	*fork);
int			to_ms(struct timeval t);
void		ft_usleep(int ms, struct timeval f);
int			time_diff(int p, int q);

#endif