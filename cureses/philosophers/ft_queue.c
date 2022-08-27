/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:50:09 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/26 17:58:55 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_queue(t_queue *que, int size)
{
	int	idx;

	que->size = size;
	que->capacity = size;
	que->que = (int *)malloc(size * sizeof(int));
	if (que->que == NULL)
	{
		error_msg("Memory Shortage");
		return (0);
	}
	que->tail = size;
	que->head = 0;
	idx = -1;
	even_odd(que->que, size, idx);
	return (1);
}

int	pop(t_queue *que)
{
	int	ret;

	if (que->size == 0)
		return (-1);
	if (que->head == que->capacity)
	{
		error_msg("data race?");
		return (-1);
	}
	ret = que->que[que->head];
	que->head += 1;
	if (que->head == que->capacity)
		que->head = 0;
	que->size--;
	return (ret);
}

int	insert(t_queue *que, int data)
{
	if (que->tail == que->capacity)
		que->tail = 0;
	if (que->size == que->capacity)
	{
		error_msg("Queue crashed");
		return (0);
	}
	que->que[que->tail] = data;
	que->tail += 1;
	que->size++;
	return (1);
}

void	print_que(t_queue *que)
{
	int	idx;
	int	it;

	printf("head :%d  tail :%d  size:  %d\n", que->head, que->tail, que->size);
	idx = -1;
	it = que->head;
	while (++idx < que->capacity)
	{
		printf("%d ", que->que[idx]);
		it++;
	}
	printf("\n");
}
