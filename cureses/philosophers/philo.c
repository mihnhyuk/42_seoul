/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:34:05 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/25 18:12:01 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sit_at_table(t_philo *philos);

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philos;
	t_queue	eat_queue;

	input_check(argc, argv, &args);
	init_queue(&eat_queue, args.philos_n);
	init_table(&args, &philos, &eat_queue);
	sit_at_table(philos);
	free_all(philos);
	return (0);
}

static void	sit_at_table(t_philo *philos)
{
	int			idx;
	pthread_t	r;

	idx = -1;
	printf("Philosophers are going to eat\n");
	while (++idx < 3)
	{
		write(1, " . ", 3);
		sleep(1);
	}
	printf("\n");
	pthread_create(&r, NULL, routine, (void *)philos);
	dead_monitor(philos);
	pthread_join(r, NULL);
}
