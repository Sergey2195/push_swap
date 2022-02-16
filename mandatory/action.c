/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:17:00 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 17:14:53 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_mem *mem)
{
	swap(mem->stack_a);
	mem->steps++;
	write(1, "sa\n", 3);
}

void	sb(t_mem *mem)
{
	swap(mem->stack_b);
	mem->steps++;
	write(1, "sb\n", 3);
}

void	ss(t_mem *mem)
{
	swap(mem->stack_a);
	swap(mem->stack_b);
	mem->steps++;
	write(1, "ss\n", 3);
}

void	pa(t_mem *mem)
{
	if (*(mem->stack_b) == NULL)
		return ;
	push(mem->stack_b, mem->stack_a);
	mem->steps++;
	write(1, "pa\n", 3);
}

void	pb(t_mem *mem)
{
	if (*(mem->stack_a) == NULL)
		return ;
	push(mem->stack_a, mem->stack_b);
	mem->steps++;
	write(1, "pb\n", 3);
}
