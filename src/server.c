/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:17:08 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/11 11:43:34 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //borrar

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	int	c_pid;
	
	signal = 0;
	context = NULL;
	c_pid = 0;
	if (!info)
		return ;
	if (info->si_pid != 0)
		c_pid = info->si_pid;
	printf("Signal caught PID> %d\n", c_pid);
	printf("Sending confirmation to %d...\n", c_pid);
	kill(c_pid, SIGUSR1);
}

// Max PID number 99999 (32 bits)
void	print_bit(int sig_num)
{
	printf("Signal caught >%d<\n", sig_num);
	//exit(1);
}

void	start_server(struct sigaction act)
{
	pid_t	s_pid;

	s_pid = getpid();
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		printf("PID: %d Waiting for signal...\n", (int)s_pid);
		sleep(10);
	}
}
/*
 * sigaction permite personalizar una senyal.
 * Utilizando la flag SA_SIGINFO, permite detectar informacion adicional sobre
 * la senyal.
 * sa_mask hace que las senyales anyadidas sean bloqueadas. Como no nos
 * interesa ninguna en especial, la creamos vacia con sigemptyset.
 * sa_sigaction -> nos permite ejecutar una funcion cuando se reciba la senyal
 */
int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = signal_handler;
	start_server(act);
	return (0);
}
