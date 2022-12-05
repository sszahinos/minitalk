/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:17:08 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/05 14:23:09 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //borrar

void	singal_handler(int signal, siginfo_t *info, void *context)
{
	if (info->si_pid != 0)
		c_pid = info->si_pid;
}

// Max PID number 99999 (32 bits)
void	print_bit(int sig_num)
{
	printf("Signal caught >%d<\n", sig_num);
	//exit(1);
}

void	start_server(sigaction act)
{
	pid_t	s_pid;

	s_pid = getpid();
	sigaction(SIGUSR1, act, NULL);
	while (1)
	{
		printf("PID: %d Waiting for signal...\n", (int)s_pid);
		sleep(10);
	}
}

int	main(void)
{
	struct sigaction	act;
	act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = signal_handler;
	start_server(act);
	return (0);
}
