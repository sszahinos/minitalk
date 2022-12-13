/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:37:24 by sersanch          #+#    #+#             */
/*   Updated: 2022/12/13 11:41:40 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_atoi(const char *str);
int		ft_atoi_bin(int *bits, int n_bits);
char	*ft_itoa(int n);
int		*ft_itoa_bin(int n, int n_bits);
int		ft_itodec(long long int bin, int bits);

#endif
