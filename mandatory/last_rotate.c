/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:10:30 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 11:55:40 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_rotate_cicles(t_mem *mem, int steps)
{
	if (steps <= stack_size(mem->stack_a) / 2)
	{
		while (steps)
		{
			ra(mem);
			steps--;
		}
	}
	else
	{
		steps = stack_size(mem->stack_a) - steps;
		while (steps)
		{
			rra(mem);
			steps--;
		}
	}
}

void	last_rotate(t_mem *mem)
{
	t_lstack	*iter_node;
	int			steps;

	steps = 0;
	iter_node = *mem->stack_a;
	while (iter_node->order != 0)
	{
		steps++;
		iter_node = iter_node->next;
	}
	last_rotate_cicles(mem, steps);
}
