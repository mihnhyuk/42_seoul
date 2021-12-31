/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:57:01 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 14:42:01 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int	idx;
	int				flag;

	while (*big && len > 0)
	{
		idx = 0;
		flag = 1;
		while (little[idx])
		{
			if (big[idx] != little[idx] || idx >= len)
			{
				flag = 0;
				break ;
			}
			idx++;
		}
		if (flag)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
