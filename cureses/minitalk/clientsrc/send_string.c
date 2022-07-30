/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:06:39 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/30 19:18:02 by minhjang         ###   ########.fr       */
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
    send_bit(pid, (unsigned char)0);
}

static void    send_bit(int pid, unsigned char c)
{
    int idx;

    idx = 0;
    while (idx < 8)
    {
        if ((c & 1) == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
                error_msg("Send error");
            pause();
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
                error_msg("Send error");
            pause();
        }
        c = (c >> 1);
        idx++;
    }
}