/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_receive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:58:13 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/03 17:12:19 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	receive_check_handler(int signum)
{
	(void)signum;
}

void	error_catcher(int signum)
{
	(void)signum;
	exit(0);
}
