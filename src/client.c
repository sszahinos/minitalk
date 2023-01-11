/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:21 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/11 12:43:35 by sersanch         ###   ########.fr       */
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

void	send_message(int s_pid, char *message)
{
	printf("Sending PID\n");
	message = "dfasdf";
	kill(s_pid, SIGUSR1);
	//kill(s_pid, SIGUSR2);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	signal = 0;
	context = NULL;
	info = NULL;
	printf("Llega mensaje de server.\n");
	//sleep(3);
	//exit(5);
}

void	ft_exit(void)
{
	printf("Message correctly sended and has been received!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	//struct sigaction	act;
	int					s_pid;

	if (argc != 3)
	{
		printf(ARG_ERROR);
		exit(0);
	}
	//act.sa_flags = SA_SIGINFO;
	//sigemptyset(&act.sa_mask);
	//act.sa_sigaction = signal_handler;
	s_pid = ft_atoi(argv[1]);
	send_message(s_pid, argv[2]);
	while (1)
		signal(SIGUSR2, &ft_exit);
	sleep(15);
	return (0);
}
