/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:17:08 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/20 17:00:52 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	*g_byte_index_id = NULL;


static void ft_waiting_message(void)
{
	char	*s_pid;

	s_pid = ft_itoa(getpid());
	write(1, "Waiting for message... PID:\n", 28);
	write(1, &s_pid, 5);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
//	int	c_pid;
	int	bit;
	unsigned char letter;
	context = NULL;
	letter = 'X';
//	printf(">%d<\n", signal);
//	write(1, "LLEGA\n", 6);
	if (!info)
	{
		//printf("error\n");
		return ;
	}
	if (g_byte_index_id[9] == -1)
		g_byte_index_id[9] = info->si_pid;
	bit = g_byte_index_id[8];
	if (signal == SIGUSR1)
		g_byte_index_id[bit] = 0;
	else
		g_byte_index_id[bit] = 1;
	g_byte_index_id[8]++;
	if (g_byte_index_id[8] == 8)
	{
		g_byte_index_id[8] = 0;
		letter = ft_itodec(ft_atoi_bin(g_byte_index_id, 8), 8);
		write(1, &letter, 1);

	}
	usleep(100);
	kill(g_byte_index_id[9], SIGUSR1);
	if (letter == '\0')
	{
		g_byte_index_id[9] = -1;
		write(1, "\n", 1);
		ft_waiting_message();
	}
}

void	start_server(struct sigaction act)
{
	write(1, "> Server started.\n", 18);
	ft_waiting_message();
	sigaction(SIGUSR1, &act, NULL); //Empieza 
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
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
	
	g_byte_index_id = malloc(sizeof(int) * 10);
	if (!g_byte_index_id)
		return (1);
	g_byte_index_id[8] = 0;
	g_byte_index_id[9] = -1;
	act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = signal_handler;
	start_server(act);
	free(g_byte_index_id);
	return (0);
}
