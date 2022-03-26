/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:01:16 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/26 16:32:41 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>

int		ft_printf(const char *str, ...);
int		get_token_num(const char *input_str);
char	*var_to_token(char **token, const char format_char, va_list ap);
int		ft_int_length(int n, unsigned int base);
int		ft_unsigned_int_length(unsigned int n, unsigned int base);
char	*int_to_token(va_list ap);
char	*unsigned_int_to_token(va_list ap);
char	*hex_to_token(va_list ap);
char	*hex_to_token_upper(va_list ap);

#endif
