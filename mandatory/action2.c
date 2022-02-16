/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:26:37 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 17:11:30 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_lstack **from_stack, t_lstack **to_stack)
{
	t_lstack	*iter_node;

	if (iter_node == NULL)
		return ;
	iter_node = *from_stack;
	if (iter_node->next)
	{
		*from_stack = iter_node->next;
		(*from_stack)->prev = NULL;
		if (*to_stack)
		{
			iter_node->next = *to_stack;
			iter_node->next->prev = iter_node;
		}
		else
			iter_node->next = NULL;
		*to_stack = iter_node;
	}
	else
	{
		iter_node->next = *to_stack;
		*to_stack = iter_node;
		*from_stack = NULL;
	}
}

void	rotate(t_lstack **stack)
{
	t_lstack	*first_node;
	t_lstack	*last_node;

	if (!stack || !*stack)
		return ;
	first_node = *stack;
	if (first_node->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last_node = take_last_node(stack);
		first_node->next = NULL;
		last_node->next = first_node;
		first_node->prev = last_node;
	}
}

void	reverse_rotate(t_lstack **stack)
{
	t_lstack	*last_node;
	t_lstack	*first_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = take_last_node(stack);
	if (last_node)
	{
		(last_node->prev)->next = NULL;
		last_node->next = first_node;
		first_node->prev = last_node;
		*stack = last_node;
		last_node->prev = NULL;
	}
}

void	rra(t_mem *mem)
{
	reverse_rotate(mem->stack_a);
	mem->steps++;
	write(1, "rra\n", 4);
}

void	rrb(t_mem *mem)
{
	reverse_rotate(mem->stack_b);
	mem->steps++;
	write(1, "rrb\n", 4);
}
