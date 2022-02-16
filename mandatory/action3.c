/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:33:13 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 17:09:45 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_mem *mem)
{
	reverse_rotate(mem->stack_a);
	reverse_rotate(mem->stack_b);
	mem->steps++;
	write(1, "rrr\n", 4);
}

void	ra(t_mem *mem)
{
	rotate(mem->stack_a);
	mem->steps++;
	write(1, "ra\n", 3);
}

void	rb(t_mem *mem)
{
	rotate(mem->stack_b);
	mem->steps++;
	write(1, "rb\n", 3);
}

void	rr(t_mem *mem)
{
	rotate(mem->stack_a);
	rotate(mem->stack_b);
	mem->steps++;
	write(1, "rr\n", 3);
}
