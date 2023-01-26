/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:16:58 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/26 10:28:17 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

int	*ft_itoa_bin(int n, int n_bits)
{
	int	*bits;
	int	bit;

	bits = malloc(sizeof(int) * n_bits);
	if (!bits)
		return (NULL);
	bit = 0;
	while (bit < n_bits)
	{
		bits[(n_bits - 1) - bit] = n & 1;
		n >>= 1;
		bit++;
	}
	return (bits);
}
