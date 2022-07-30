/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:58:28 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/30 17:58:55 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include "../libft/includes/ft_printf.h"
#include "../libft/libft/libft.h"
#include <unistd.h>
#include <signal.h>

void    send_string_sig(int pid, char * sig);
void    receive_check_handler(int signum);

#endif