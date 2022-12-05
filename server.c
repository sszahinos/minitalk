/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:17:08 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/05 10:27:31 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //borrar

// Max PID number 99999 (32 bits)
void	print_bit(int sig_num)
{
	printf("Signal caught >%d<\n", sig_num);
	//exit(1);
}

void	start_server(void)
{
	pid_t	pid;

	pid = getpid();
	signal(SIGUSR1, print_bit);
	while (1)
	{
		printf("PID: %d Waiting for signal...\n", (int)pid);
		sleep(10);
	}
}

int	main(int argc, char** argv)
{
	argc = 1;
	if (argv)
		;
	start_server();
	return (0);
}
