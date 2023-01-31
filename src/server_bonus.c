/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:10:46 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/26 14:11:34 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * sigaction permite personalizar una senyal.
 * Utilizando la flag SA_SIGINFO, permite detectar informacion adicional sobre
 * la senyal.
 * sa_mask hace que las senyales anyadidas sean bloqueadas. Como no nos
 * interesa ninguna en especial, la creamos vacia con sigemptyset.
 * sa_sigaction -> nos permite ejecutar una funcion cuando se reciba la senyal
 */

int	*g_byte_index_id = NULL;

static void	ft_waiting_message(void)
{
	char	*s_pid;

	s_pid = ft_itoa(getpid());
	write(1, "\nWaiting for message... PID:", 28);
	ft_putstr(s_pid);
	write(1, "\n", 1);
}

static unsigned char	ft_check_letter(void)
{
	unsigned char	letter;

	if (g_byte_index_id[8] == 8)
	{
		g_byte_index_id[8] = 0;
		letter = ft_itodec(ft_atoi_bin(g_byte_index_id, 8), 8);
		write(1, &letter, 1);
	}
	else
		letter = 'X';
	return (letter);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	int				bit;
	unsigned char	letter;

	context = NULL;
	if (g_byte_index_id[9] == -1)
		g_byte_index_id[9] = info->si_pid;
	bit = g_byte_index_id[8];
	if (signal == SIGUSR1)
		g_byte_index_id[bit] = 0;
	else
		g_byte_index_id[bit] = 1;
	g_byte_index_id[8]++;
	letter = ft_check_letter();
	usleep(100);
	kill(g_byte_index_id[9], SIGUSR1);
	if (letter == '\0')
	{
		g_byte_index_id[9] = -1;
		ft_waiting_message();
	}
}

static void	start_server(struct sigaction act)
{
	write(1, "> Server started.\n", 18);
	ft_waiting_message();
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
}

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
