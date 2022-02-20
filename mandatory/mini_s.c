/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:34:40 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/16 14:17:03 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three_numbers_a(t_mem *mem)
{
	t_lstack	*first;
	t_lstack	*second;
	t_lstack	*third;

	first = *mem->stack_a;
	second = first->next;
	third = second->next;
	if (first->number > second->number && first->number < third->number)
		sa(mem);
	else if (first->number > second->number && second->number > third->number)
	{
		sa(mem);
		rra(mem);
	}
	else if (first->number < second->number && first->number > third->number)
		rra(mem);
	else if (first->number < third->number && second->number > third->number)
	{
		rra(mem);
		sa(mem);
	}
	else if (third->number > second->number && first->number > third->number)
		ra(mem);
}

void	sorting_three_numbers_b(t_mem *mem)
{
	t_lstack	*first;
	t_lstack	*second;
	t_lstack	*third;

	first = *mem->stack_b;
	second = first->next;
	third = second->next;
	if (first->number > second->number && first->number < third->number)
		sb(mem);
	else if (first->number > second->number && second->number > third->number)
	{
		sb(mem);
		rrb(mem);
	}
	else if (first->number < second->number && first->number > third->number)
		rrb(mem);
	else if (first->number < third->number && second->number > third->number)
	{
		rrb(mem);
		sb(mem);
	}
	else if (third->number > second->number && first->number > third->number)
		rb(mem);
}

void	merging_two_stacks(t_mem *mem)
{
	while (*mem->stack_b)
	{
		if ((*mem->stack_b)->order < (*mem->stack_a)->order)
		{
			pa(mem);
			ra(mem);
		}
		else if ((*mem->stack_b)->order - (*mem->stack_a)->order == 1)
		{
			ra(mem);
			pa(mem);
		}
		else
			ra(mem);
	}
	while ((*mem->stack_a)->order != 0)
		ra(mem);
}

void	sorting_between_four_six(t_mem *mem)
{
	while (stack_size(mem->stack_a) > 3)
		pb(mem);
	if (sort_check(mem->stack_a) == 0)
		sorting_three_numbers_a(mem);
	if (stack_size(mem->stack_b) == 2)
	{
		if (sort_check(mem->stack_b) == 0)
			sb(mem);
	}
	else if (stack_size(mem->stack_b) == 3)
	{
		if (sort_check(mem->stack_b) == 0)
			sorting_three_numbers_b(mem);
	}
	merging_two_stacks(mem);
	return ;
}
