/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:27:45 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/03 17:02:37 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/includes/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_dynamicStr
{
	char	*str;
	int		capacity;
	int		length;
}			t_dynamicStr;

void	sig_handler1(int signum, siginfo_t *info, void *context);
void	sig_handler2(int signum, siginfo_t *info, void *context);
int		push_back(t_dynamicStr *str, char c);
int		error_msg(char *msg);
int		decoder(unsigned char bit);

#endif