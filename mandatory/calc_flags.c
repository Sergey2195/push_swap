/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:05:32 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 12:04:14 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_to_top_b(t_mem *mem, t_lstack *node)
{
	t_lstack	*iter_node;
	int			steps;

	steps = 0;
	iter_node = *mem->stack_b;
	while (iter_node->order != node->order)
	{
		iter_node = iter_node->next;
		steps++;
	}
	if (steps <= stack_size(mem->stack_b) / 2)
		return (steps);
	else
		return (steps - stack_size(mem->stack_b));
}

int	steps_to_closest_a(t_mem *mem, t_lstack *calc_node)
{
	int			closest;
	int			counter;
	int			steps;
	t_lstack	*iter_node;

	steps = 0;
	counter = 0;
	closest = mem->max_order;
	iter_node = *mem->stack_a;
	while (iter_node)
	{
		if ((iter_node->order <= closest)
			&& (iter_node->order > calc_node->order))
		{
			closest = iter_node->order;
			steps = counter;
		}
		iter_node = iter_node->next;
		counter++;
	}
	if (steps <= stack_size(mem->stack_a) / 2)
		return (steps);
	else
		return (steps - stack_size(mem->stack_a));
}
