/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:53:19 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 13:19:45 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_lstack **stack)
{
	int			*numbers;
	int			i;
	int			j;
	int			flag;
	t_lstack	*iter_node;

	i = 0;
	flag = 0;
	numbers = malloc(sizeof(int) * (stack_size(stack)));
	iter_node = *stack;
	while (iter_node)
	{
		j = 0;
		while (j < i)
		{
			if (numbers[j++] == iter_node->number)
				flag = -1;
		}
		numbers[i] = iter_node->number;
		i++;
		iter_node = iter_node->next;
	}
	free(numbers);
	return (flag);
}

int	check_is_numbers(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		if (str[i] == NULL || str[i][0] == '\0')
			return (-1);
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < 48 || str[i][j] > 57) && \
			(str[i][j] != '-' && str[i][j] != '+'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	args_check(char **argv, t_lstack **stack)
{
	if (check_is_numbers(argv) == -1)
		return (-1);
	else if (check_duplicates(stack) == -1)
		return (-1);
	else
		return (0);
}

int	sort_check(t_lstack **stack)
{
	t_lstack	*iter_node;

	iter_node = *stack;
	while ((iter_node)->next != NULL)
	{
		if ((iter_node)->number < ((iter_node)->next)->number)
		{
			iter_node = (iter_node)->next;
			continue ;
		}
		else
			return (0);
	}
	return (-1);
}
