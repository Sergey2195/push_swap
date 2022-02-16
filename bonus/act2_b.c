/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act2_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:20:14 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 16:25:01 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	b_rra(t_mem *mem)
{
	reverse_rotate(mem->stack_a);
	mem->steps++;
}

void	b_rrb(t_mem *mem)
{
	reverse_rotate(mem->stack_b);
	mem->steps++;
}