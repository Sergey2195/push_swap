/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:02:17 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/16 14:17:16 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_orders(t_lstack **stack)
{
	int			position_order;
	int			find_min_num;
	t_lstack	*iter_node;
	t_lstack	*node;

	position_order = 0;
	while (position_order < stack_size(stack))
	{
		iter_node = *stack;
		find_min_num = 2147483647;
		while (iter_node)
		{
			if (iter_node->order == -1 && iter_node->number <= find_min_num)
			{
				node = iter_node;
				find_min_num = iter_node->number;
			}
			iter_node = iter_node->next;
		}
		node->order = position_order;
		position_order++;
	}
}

void	swap(t_lstack **stack)
{
	t_lstack	*first_node;
	t_lstack	*second_node;

	first_node = *stack;
	if (!stack || !*stack || !first_node->next)
		return ;
	second_node = first_node->next;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	second_node->prev = NULL;
	first_node->prev = second_node;
	*stack = second_node;
}

t_lstack	*take_last_node(t_lstack **stack)
{
	t_lstack	*iter_node;

	iter_node = *stack;
	while (iter_node->next)
		iter_node = iter_node->next;
	return (iter_node);
}

int	ft_check_zero(int num, char *str)
{
	if (num == 0)
	{
		if (str[0] == '0' && str[1] == '\0')
			return (0);
		else
			return (-1);
	}
	else
		return (0);
}
