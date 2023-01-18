/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:21 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/18 12:48:57 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h> //borrar

int *char_byte;

static void	send_bit(int pid, int bit)
{
//	printf("entra bit >%d<\n", bit);
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	pause();
}

static void	send_message(int s_pid, char *message, struct sigaction act)
{
	int	i;
	
	sigaction(SIGUSR1, &act, NULL);
	while (*message)
	{
		char_byte = ft_itoa_bin((int)*message, 8);//paso caracter a byte
		i = 0;
//		printf("%d%d%d%d%d%d%d%d\n", char_byte[0],char_byte[1],char_byte[2],char_byte[3],char_byte[4],char_byte[5],char_byte[6],char_byte[7]);
		while (i < 8)
		{
//			write(1, "send_bit\n", 9);
			send_bit(s_pid, char_byte[i++]);
		//	write(1, "after", 5);
		/*	if (!sleep(10))
			{
				write(1, "Server not responding. Abort!\n", 30);
				exit(6);
			}
			else
				write(1, "OK\n", 3);*/
		}
		free(char_byte);
		message++;
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	signal = 0;
	context = NULL;
	info = NULL;
//	write(1, "recibe\n", 7); 
	//printf("Llega mensaje de server.\n");
	//sleep(3);
	//exit(5);
}
/*
void	ft_exit(int what)
{
	what = 1;
	printf("Message correctly sended and has been received!\n");
	exit(1);
}*/
/* No usar PRINTF de forma asincrona
 * */
int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					s_pid;

	if (argc != 3)
	{
		printf(ARG_ERROR);
		exit(0);
	}
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = signal_handler;
	s_pid = ft_atoi(argv[1]);
	send_message(s_pid, argv[2], act);
	return (0);
}
