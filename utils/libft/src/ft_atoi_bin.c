/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:36:20 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/13 11:49:21 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi_bin(int *bits, int n_bits)
{ 
	int multiplier;
	int bin;
	int	i;
	
	multiplier = 1;
	bin = 0;
	i = n_bits - 1;
	while (i >= 0)
	{
		bin += multiplier * bits[i];
		multiplier *= 10;
		i--;
	}
	return (bin);
}
