/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:17:08 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/13 14:39:36 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //borrar

int	*g_byte_index = NULL;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	int	c_pid;
	int	aux;
	char letter;
//	write(1, "\nENTRA\n", 7);	
	//signal = 0;
	context = NULL;
	c_pid = 0;
	if (!info)
	{
		//printf("error\n");
		return ;
	}
	if (info->si_pid != 0)
		c_pid = info->si_pid;
//	printf("signal> %d? vs %d = %d\n", signal, SIGUSR1, signal == SIGUSR1);
	aux = g_byte_index[8];
	if (signal == SIGUSR1)
	{	
		g_byte_index[aux] = 0;
//		write(1, "0", 1);
	}
	else
	{
		g_byte_index[aux] = 1;
//		write(1, "1", 1);
	}
	g_byte_index[8]++;
	if (g_byte_index[8] == 8)
	{
		g_byte_index[8] = 0;
		letter = ft_itodec(ft_atoi_bin(g_byte_index, 8), 8);
		write(1, &letter, 1);
	}
	//printf("Signal caught PID> %d\n", c_pid);
	
	//pause();
	//printf("Sending confirmation to %d...\n", c_pid);
	usleep(100);
	kill(c_pid, SIGUSR1);
	//bits = malloc(sizeof(int) * 8);
}

/*
// Max PID number 99999 (32 bits)
void	print_bit(int sig_num)
{
	printf("Signal caught >%d<\n", sig_num);
	//exit(1);
}*/

void	start_server(struct sigaction act)
{
	pid_t	s_pid;

	s_pid = getpid();
	printf("> Server started. PID: %d\n", s_pid);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL); //Empieza 
		sigaction(SIGUSR2, &act, NULL);
		//printf("PID: %d Waiting for signal...\n", (int)s_pid);
		//sleep(10);
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
	
	g_byte_index = malloc(sizeof(int) * 9);
	g_byte_index[8] = 0;
	act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = signal_handler;
	start_server(act);
	free(g_byte_index);
	return (0);
}
