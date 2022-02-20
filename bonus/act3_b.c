/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act3_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:22:54 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/16 12:24:34 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	b_rrr(t_mem *mem)
{
	reverse_rotate(mem->stack_a);
	reverse_rotate(mem->stack_b);
	mem->steps++;
}

void	b_ra(t_mem *mem)
{
	rotate(mem->stack_a);
	mem->steps++;
}

void	b_rb(t_mem *mem)
{
	rotate(mem->stack_b);
	mem->steps++;
}

void	b_rr(t_mem *mem)
{
	rotate(mem->stack_a);
	rotate(mem->stack_b);
	mem->steps++;
}
