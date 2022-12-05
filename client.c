/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:21 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/05 12:11:41 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h> //borrar

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
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_num((int)argv[1], (int)getpid(), 24);
		send_message((int)argv[1], argv[2]);
	}
	return (0);
}
