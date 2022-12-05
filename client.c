/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:21 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/01 12:23:08 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h> //borrar

/*void	send_bit(char c)
{
	kill();
}*/

void	send_message(int pid, char* message)
{
	int	i;
	//struct sigaction	act;

	i = 0;
	while (message[i])
	{
		send_bit(message[i]);
		i++;
	}
	send_bit('\0');
}

int	main(int argc, char** argv)
{
	if (argc == 3)
		send_message((int)argv[1], argv[2]);
	return (0);
}
