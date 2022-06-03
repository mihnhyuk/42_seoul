/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:03:51 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/03 21:31:09 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static int	*ft_qsort(int pivot, int *ary, int len);
static int	*merge(int *left, int *right, int pivot, int *len);

int	find_pivot(t_stack *a, int range)
{
	int	*sorted_ary;
	int	idx;
	int	pivot;

	sorted_ary = (int *)malloc((a->top + 1) * sizeof(int));
	idx = 0;
	while (idx < range)
	{
		sorted_ary[idx] = a->ary[a->top - idx];
		idx++;
	}
	sorted_ary = ft_qsort(sorted_ary[0], sorted_ary, range);
	pivot = sorted_ary[range / 2];
	return (pivot);
}

static int	*ft_qsort(int pivot, int *ary, int len)
{
	int	*left;
	int	*right;
	int	idx[3];

	if (len <= 1)
		return (ary);
	left = (int *)malloc((len) * sizeof(int));
	right = (int *)malloc((len) * sizeof(int));
	if (left == NULL || right == NULL)
		return (NULL);
	idx[2] = -1;
	idx[0] = 0;
	idx[1] = 0;
	while (++(idx[2]) < len)
	{
		if (ary[idx[2]] < pivot)
			left[(idx[0])++] = ary[idx[2]];
		else if (ary[idx[2]] > pivot)
			right[(idx[1])++] = ary[idx[2]];
	}
	free(ary);
	left = ft_qsort(left[0], left, (idx[0]));
	right = ft_qsort(right[0], right, (idx[1]));
	return (merge(left, right, pivot, idx));
}

static int	*merge(int *left, int *right, int pivot, int *len)
{
	int	*result;
	int	idx;

	result = (int *)malloc((len[0] + len[1] + 1) * sizeof(int));
	idx = 0;
	while (idx < len[0])
	{
		result[idx] = left[idx];
		idx++;
	}
	result[idx] = pivot;
	while (++idx < len[0] + 1 + len[1])
		result[idx] = right[idx - len[0] - 1];
	free(left);
	free(right);
	return (result);
}
