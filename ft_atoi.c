/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:27:45 by iannmari          #+#    #+#             */
/*   Updated: 2022/01/19 16:56:10 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

long int	ft_num(char *str, int z)
{
	long int	i;
	long int	k;

	i = 0;
	k = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		k = k * 10 + (str[i] - 48);
		i++;
	}
	if (z == 1)
		k = -k;
	return (k);
}

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	z;
	long int	y;

	i = 0;
	z = 0;
	y = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			z = 1;
		i++;
	}
	if (str[i] > 47 && str[i] < 58)
		y = ft_num((char *)str + i, z);
	if (y > 2147483647 || y < -2147483648)
		y = 0;
	return (y);
}
