/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:21 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/13 12:35:17 by sersanch         ###   ########.fr       */
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
//	int	*bin_num;
//	int i;

	printf("entra bit >%d<\n", bit);
//	bin_num = ft_itoa_bin(num, n_bits);

//	i = 0;
//	while (i < n_bits)
//	{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
//		i++;
//		if (!sleep(5))
//		{
//			free(bin_num);
//			exit(2);
//		}
//	}
}

static void	send_message(int s_pid, char *message, struct sigaction act)
{
	int	i;
	
	printf("Sending message\n");
//	message_len = ft_strlen(message);
	while (*message)
	{
		printf("entra mensaje\n");
		char_byte = ft_itoa_bin((int)*message, 8);//paso caracter a byte
		i = 0;
		printf("%d%d%d%d%d%d%d%d\n", char_byte[0],char_byte[1],char_byte[2],char_byte[3],char_byte[4],char_byte[5],char_byte[6],char_byte[7]);
		//send_bit(s_pid, char_byte[i++]);
		while (i < 8)
		{
			write(1, "send_bit\n", 9);
			send_bit(s_pid, char_byte[i++]);
			sigaction(SIGUSR1, &act, NULL);
			sleep(60); //PROTEGER SLEEP
//			send_bit(s_pid, char_byte[i++]); //mando cada bit del byte
//			sleep(2);
		}
//		sigaction(SIGUSR1, &act, NULL);
//		printf("sale\n");
		free(char_byte);
		message++;
	}
/*	message = "dfasdf";
	printf("Manda 1\n");
	kill(s_pid, SIGUSR1);
	sleep(2);
	printf("Manda 2\n");
	kill(s_pid, SIGUSR2);*/
	//send_num(s_pid, 2, 8);
	//kill(s_pid, SIGUSR1);
	//kill(s_pid, SIGUSR2);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	signal = 0;
	context = NULL;
	info = NULL;
	write(1, "recibe\n", 7); 
	//printf("Llega mensaje de server.\n");
	//sleep(3);
	//exit(5);
}

void	ft_exit(int what)
{
	what = 1;
	printf("Message correctly sended and has been received!\n");
	exit(1);
}
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
	//printf("asdfasdf\n");
	//while (1)
	//	signal(SIGUSR2, ft_exit);
	return (0);
}
