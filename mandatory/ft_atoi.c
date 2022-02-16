/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:16:34 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/14 14:57:19 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	str_to_nbr(const char *s)
{
	int			i;
	long long	number;

	i = 0;
	number = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			break ;
		number = number * 10 + (s[i] - '0');
		i++;
	}
	return (number);
}	

long long	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || \
		str[i] == '\r' || str[i] == '\n' || str[i] == 32)
			i++;
		if (str[i] == '-')
			return (str_to_nbr(&str[i + 1]) * -1);
		else if (str[i] == '+')
			return (str_to_nbr(&str[i + 1]));
		else
			return (str_to_nbr(&str[i]));
	}
	return (0);
}
