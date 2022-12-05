/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:16:58 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/05 10:26:43 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	*ft_itoa_bin(int n, int n_bits)
{
//  int n_bits = 32;
 // int input = 99999;
	int *bits;
 
	bits = malloc(sizeof(int) * n_bits);
	if (!bits)
		return (NULL);
	bit = 0;
	while (bit < n_bits)
	{
		bits[(n_bits - 1) - bit ] = input & 1;
		input >>= 1;
		bit++;
	}
}

/*
int	main(void)
{
	int i = 0;
	while (i < 32)
	{
		printf("%d", bits[i]);
		i++;
	}
	return 0;

}*/
