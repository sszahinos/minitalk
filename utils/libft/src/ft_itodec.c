/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itodec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:08:29 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/05 11:25:34 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itodec(long long int bin, int bits)
{
	int dec_num;
	int	base;
	int	rem;

	dec_num = 0;
	base = 1;
	while (i < bits)  
    {  
        rem = bin % 10; 
        dec_num += rem * base;  
        bin = bin / 10; 
        base = base * 2;
    }
	return (dec_num);
}
