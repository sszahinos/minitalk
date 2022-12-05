/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:37:33 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/05 09:37:57 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long long int n)
{
	int	i;
	int	sign;

	if (n == 2147483648)
		return (11);
	i = 0;
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i + sign);
}

static char	*get_min(char *num)
{
	char	*min;
	int		i;

	min = "-2147483648";
	i = 0;
	while (i < 12)
	{
		num[i] = min[i];
		i++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	i = get_len(n) - 1;
	num = malloc(sizeof(char) * (get_len(n) + 1));
	if (!num)
		return (0);
	if (n == -2147483648LL)
		return (get_min(num));
	num[i + 1] = '\0';
	if (n < 0)
	{
		n *= -1;
		num[0] = '-';
	}
	else if (n == 0)
	{
		num[0] = '0';
	}
	while (n > 0)
	{
		num[i--] = (char)(n % 10) + 48;
		n /= 10;
	}
	return (num);
}
