/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:17:08 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/18 13:53:22 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //borrar

int	*g_byte_index = NULL;
/*
void	signal_handler(int signal, siginfo_t *info, void *context)
{
	int	c_pid;
	int	bit;
	char letter;
	context = NULL;
	if (!info)
	{
		//printf("error\n");
		return ;
	}
	c_pid = info->si_pid;
	bit = g_byte_index[8];
	if (signal == SIGUSR1)
	{	
		g_byte_index[bit] = 0;
//		write(1, "0", 1);
	}
	else
	{
		g_byte_index[bit] = 1;
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
	usleep(700);
	kill(c_pid, SIGUSR1);
}
*/
void	signal_handler(int signal, siginfo_t *info, void *context)
{
	context = NULL;
	if (signal == SIGUSR1)
		g_byte_index[g_byte_index[8]] = 0;
	else
		g_byte_index[g_byte_index[8]] = 1;
	kill(info->si_pid, SIGUSR1);
}

void	start_server(struct sigaction act)
{
	pid_t	s_pid;
	char letter;


	s_pid = getpid();
	printf("> Server started. PID: %d\n", s_pid);
	sigaction(SIGUSR1, &act, NULL); //Empieza 
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
		usleep(100);
		g_byte_index[8]++;
		if (g_byte_index[8] == 8)
		{
			g_byte_index[8] = 0;
			letter = ft_itodec(ft_atoi_bin(g_byte_index, 8), 8);
			write(1, &letter, 1);
		}
		//kill(c_pid, SIGUSR1);
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
