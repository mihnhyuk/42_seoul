/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:55:44 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 14:55:39 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while ((s1[idx] && s2[idx]) && idx + 1 < n && s1[idx] == s2[idx])
		idx++;
	return ((const unsigned char)s1[idx] - (const unsigned char)s2[idx]);
}
