/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:28:46 by sersanch          #+#    #+#             */
/*   Updated: 2023/01/26 10:29:12 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr(char *s)
{
	int	i;
	int	printed;
	int	aux;

	printed = 0;
	i = 0;
	while (s[i])
	{
		aux = ft_putchar(s[i]);
		if (aux < 0)
			return (-1);
		printed += aux;
		i++;
	}
	return (printed);
}
