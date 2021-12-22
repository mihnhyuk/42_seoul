/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:17:45 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/16 20:17:47 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
		return (s);
	return (0);
}

char	*strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s)
	{
		if (*s == c)
		{
			result = s;
		}
		s++;
	}
	if (c == '\0')
		return (s);
	return (result);
}

char	*strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int	idx;
	bool			flag;

	while (*big && len > 0)
	{
		idx = 0;
		flag = true;
		while (little[idx])
		{
			if (big[idx] != little[idx])
			{
				flag = false;
				break ;
			}
			idx++;
		}
		if (flag)
			return (big);
		big++;
		len--;
	}
	return (0);
}
