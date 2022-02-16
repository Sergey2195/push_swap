/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:00:59 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 17:17:05 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	b_sa(t_mem *mem)
{
	swap(mem->stack_a);
	mem->steps++;
}

void	b_sb(t_mem *mem)
{
	swap(mem->stack_b);
	mem->steps++;
}

void	b_ss(t_mem *mem)
{
	swap(mem->stack_a);
	swap(mem->stack_b);
	mem->steps++;
}

void	b_pa(t_mem *mem)
{
	if (*(mem->stack_b) == NULL)
		return ;
	push(mem->stack_b, mem->stack_a);
	mem->steps++;
}

void	b_pb(t_mem *mem)
{
	if (*(mem->stack_a) == NULL)
		return ;
	push(mem->stack_a, mem->stack_b);
	mem->steps++;
}
