/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:06:39 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/30 18:01:01 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void    send_bit(int pid, unsigned char c);

void    send_string_sig(int pid, char * sig)
{
    while (*sig)
    {
        send_bit(pid, (unsigned char)*sig);
        sig++;
    }
}

static void    send_bit(int pid, unsigned char c)
{
    int idx;

    idx = 0;
    while (idx < 8)
    {
        if ((c & 1) == 0)
        {
            ft_printf("0: %d\n", kill(pid, SIGUSR1));
            pause();
        }
        else
        {
            ft_printf("1: %d\n", kill(pid, SIGUSR2));
            pause();
        }
        c = (c >> 1);
        idx++;
    }
}