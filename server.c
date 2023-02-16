/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:57:09 by abenlahb          #+#    #+#             */
/*   Updated: 2023/02/16 11:30:53 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void signal_handler(int sig)
{
    unsigned char d = 0;
    unsigned char e = 255;
    static int i = 7;
    static uint8_t c = 128;
    if(sig == SIGUSR2)
        c  = (int8_t)c >> 1;
    if(sig == SIGUSR1)
        c = c >> 1;
    i--;
   
        printf("%d\n",c);
}

int main(int argc,char **argv)
{
    pid_t pid;
    pid = getpid();
    signal(SIGUSR1,signal_handler);
    signal(SIGUSR2,signal_handler);
    printf("The Server PID is :");
    printf("%d\n",pid);
    while(1)
        pause();
}