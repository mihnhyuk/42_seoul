/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:55:44 by minhjang          #+#    #+#             */
/*   Updated: 2022/04/11 13:12:44 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	idx;

	idx = 0;
	while (s1[idx] && s2[idx])
		idx++;
	return ((const unsigned char)s1[idx] - (const unsigned char)s2[idx]);
}
