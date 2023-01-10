/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:21 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/13 15:32:44 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h> //borrar
/*
void	send_num(int pid, int num, int n_bits)
{
	int	*bin_num;
	int i;

	bin_num = ft_itoa_bin(num, n_bits);
	i = 0;
	while (i < n_bits)
	{
		if (bin_num[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		pause();
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_num((int)message[i]);
		i++;
	}
	send_num((int)'\0');
}*/

void	send_pid(s_pid)
{
	printf("Sending PID\n");
	kill(s_pid, SIGUSR1);
	pause();
	printf("Recibido!\n");
	//kill(s_pid, SIGUSR2);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	signal = 0;
	context = NULL;
	info = NULL;
	printf("Llega mensaje de server.\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					s_pid;

	if (argc != 3)
	{
		printf(ARG_ERROR);
		exit(0);
//		send_num((int)argv[1], (int)getpid(), 24);
//		send_message((int)argv[1], argv[2]);
	}
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = signal_handler;
	s_pid = ft_atoi(argv[1]);
	send_pid(s_pid);
//	sigaction(SIGUSR1, &act, NULL);
/*	while (1)
	{
		printf("Client PID> %d\n", c_pid);
		send_pid(9211);
		sleep(10);
	}*/

	return (0);
}
