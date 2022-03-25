/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:01:16 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/25 16:52:45 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>

int		ft_printf(const char *str, ...);
int		get_token_num(const char *input_str);
char	*var_to_token(char **token, const char format_char, va_list ap);

#endif
