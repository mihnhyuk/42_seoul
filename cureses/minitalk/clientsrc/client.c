/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:57:33 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/04 09:03:15 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	pid_check(char *pid);

int	main(int argc, char **argv)
{
	unsigned int	pid;

	if (argc != 3)
		return (error_msg("You must enter pid and string"));
	pid = pid_check(argv[1]);
	if (pid == (unsigned int)-1)
		return (error_msg("pid range error"));
	signal(SIGUSR1, receive_check_handler);
	signal(SIGUSR2, error_catcher);
	send_string_sig(pid, argv[2]);
	return (0);
}

static int	pid_check(char *pid)
{
	int	atoid;

	atoid = ft_atoi(pid);
	if (atoid < 101 || atoid > 100000)
		return (-1);
	else
		return (atoid);
}

int	error_msg(char *msg)
{
	ft_printf("%s\n", msg);
	return (-1);
}
