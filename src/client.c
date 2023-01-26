/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:21 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/26 10:19:14 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void	send_bit(int pid, int bit)
{
	int	signal;

	if (bit == 0)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	kill(pid, signal);
}

static int	send_byte(char *message, int s_pid)
{
	int	i;
	int	*char_byte;

	char_byte = ft_itoa_bin((int)*message, 8);
	i = 0;
	while (i < 8)
	{
		send_bit(s_pid, char_byte[i++]);
		if (!sleep(10))
		{
			write(1, "Server not responding...\n", 25);
			free(char_byte);
			return (-1);
		}
	}
	free(char_byte);
	return (0);
}

static int	send_message(int s_pid, char *message, struct sigaction act)
{
	sigaction(SIGUSR1, &act, NULL);
	while (*message)
	{
		if (send_byte(message, s_pid) == -1)
			return (-1);
		message++;
	}
	send_byte(message, s_pid);
	return (0);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	signal = 0;
	context = NULL;
	info = NULL;
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					s_pid;

	if (argc != 3)
	{
		write(1, "Arguments error. Abort!\n", 24);
		return (0);
	}
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = signal_handler;
	s_pid = ft_atoi(argv[1]);
	if (send_message(s_pid, argv[2], act) == -1)
		write(1, "Abort!\n", 7);
	else
		write(1, "Message correctly sended and has been received!\n", 48);
	return (0);
}
