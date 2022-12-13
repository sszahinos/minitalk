/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:34:58 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/13 11:45:15 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	if (c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_valid(char c)
{
	if (is_num(c) == 1 || c == '+' || c == '-')
		return (1);
	return (0);
}

static int	get_int(const char *str, int i, int sign)
{
	int	num;

	num = 0;
	while (is_num(str[i]) == 1)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (is_space(str[i]) == 1)
		i++;
	if (is_valid(str[i]) == 1)
	{
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
	}
	if (is_num(str[i] == 0))
		return (0);
	else
		return (get_int(str, i, sign));
}

