/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:31:32 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/17 19:54:12 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while ((s1[idx] && s2[idx]) && idx + 1 < n)
	{
		if (s1[idx] == s2[idx])
			idx++;
		else
			return (s1[idx] - s2[idx]);
	}
	return (s1[idx] - s2[idx]);
}
