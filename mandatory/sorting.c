/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:01:07 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 12:03:05 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	modulus(int value)
{
	if (value < 0)
		return (value * (-1));
	else
		return (value);
}

void	send_up_mid_and_pb(t_mem *mem)
{
	int			count;
	int			fl;
	t_lstack	*node;

	count = 0;
	fl = 0;
	node = *mem->stack_a;
	while (node->order != mem->mid_order)
	{
		count++;
		node = node->next;
	}
	if (count <= stack_size(mem->stack_a) / 2)
		fl = 1;
	while ((*mem->stack_a)->order != mem->mid_order)
	{
		if (fl == 1)
			ra(mem);
		else
			rra(mem);
	}
	pb(mem);
}

void	send_to_b_except_min_and_max(t_mem *mem)
{
	while (*mem->stack_a)
	{
		if ((*mem->stack_a)->order == 0 \
		|| (*mem->stack_a)->order == mem->max_order)
		{
			if (stack_size(mem->stack_a) == 2)
				break ;
			ra(mem);
		}
		else
		{
			if ((*mem->stack_a)->order < mem->mid_order)
				pb(mem);
			else if ((*mem->stack_a)->order > mem->mid_order)
			{
				pb(mem);
				rb(mem);
			}
		}
	}
}

void	give_flags(t_mem *mem)
{
	t_lstack	*calc_node;
	int			to_top_b;
	int			to_closest_a;

	calc_node = *mem->stack_b;
	while (calc_node)
	{
		to_top_b = steps_to_top_b(mem, calc_node);
		to_closest_a = steps_to_closest_a(mem, calc_node);
		calc_node->flag = modulus(to_closest_a) + modulus(to_top_b) + 1;
		calc_node = calc_node->next;
	}
}

void	sorting(t_mem *mem)
{
	send_up_mid_and_pb(mem);
	send_to_b_except_min_and_max(mem);
	while (*mem->stack_b)
	{
		give_flags(mem);
		push_min_flag(mem);
	}
	last_rotate(mem);
}
