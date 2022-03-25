/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:52:21 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/25 16:59:12 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_int_length(int n, unsigned int base);
int				ft_unsigned_int_length(unsigned int n, unsigned int base);
char			*ft_strdup(char *src);
void			ft_putstr_fd(char *s, int fd);
unsigned int	ft_strlen(const char *str);

#endif
