/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:58:23 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/16 19:09:00 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_b_to_top(t_mem *mem, int b_steps)
{
	while (b_steps > 0)
	{
		rb(mem);
		b_steps--;
	}
	while (b_steps < 0)
	{
		rrb(mem);
		b_steps++;
	}	
}

void	send_a_to_top(t_mem *mem, int a_steps)
{
	while (a_steps > 0)
	{
		ra(mem);
		a_steps--;
	}
	while (a_steps < 0)
	{
		rra(mem);
		a_steps++;
	}
}

void	put_nodes_to_top(t_mem *mem, int a_steps, int b_steps)
{
	while (a_steps > 0 && b_steps > 0)
	{
		rr(mem);
		a_steps--;
		b_steps--;
	}
	while (a_steps < 0 && b_steps < 0)
	{
		rrr(mem);
		a_steps++;
		b_steps++;
	}
	send_a_to_top(mem, a_steps);
	send_b_to_top(mem, b_steps);
}

void	push_min_flag(t_mem *mem)
{
	int			min_flag;
	t_lstack	*iter_node;
	t_lstack	*mem_node;
	int			tca;
	int			ttb;

	min_flag = mem->max_order;
	iter_node = *mem->stack_b;
	while (iter_node)
	{
		if (iter_node->flag <= min_flag)
		{
			min_flag = iter_node->flag;
			mem_node = iter_node;
		}
		iter_node = iter_node->next;
	}
	tca = steps_to_closest_a(mem, mem_node);
	ttb = steps_to_top_b(mem, mem_node);
	put_nodes_to_top(mem, tca, ttb);
	pa(mem);
}
