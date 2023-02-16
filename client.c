/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:57:38 by abenlahb          #+#    #+#             */
/*   Updated: 2023/02/16 11:31:50 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void chois_signel(int pid,char c)
{
    int i = 0;
    unsigned char a = 127;
    while(a)
    {
        if(a & c)
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);
        usleep(100);
        a = a >> 1;
    }
    
}
int main(int argc,char **argv)
{
    int i = -1;
    int pid = atoi(argv[1]);
    chois_signel(pid,argv[2][0]);
}