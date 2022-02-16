/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:06:44 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/14 15:01:34 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	stack_size(t_lstack **stack)
{
	int			i;
	t_lstack	*iter_node;

	if (!*stack)
		return (0);
	iter_node = *stack;
	i = 0;
	while (iter_node)
	{
		iter_node = iter_node->next;
		i++;
	}
	return (i);
}

t_lstack	*create_node(int value)
{
	t_lstack	*node;

	node = (t_lstack *)malloc(sizeof(t_lstack));
	node->number = value;
	node->order = -1;
	node->flag = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_back_node(t_lstack **stack, t_lstack *node)
{
	t_lstack	*iter_node;

	iter_node = *stack;
	while (iter_node->next != NULL)
		iter_node = iter_node->next;
	iter_node->next = node;
	node->prev = iter_node;
}

void	mem_cont(t_mem *mem)
{
	mem->max_order = stack_size(mem->stack_a) - 1;
	mem->mid_order = mem->max_order / 2;
	mem->steps = 0;
}

int	create_first_lstack(t_mem *mem, int argc, char **argv)
{
	int			i;
	long long	value;
	int			max_int;
	int			min_int;
	t_lstack	*tmp;

	max_int = 2147483647;
	min_int = -2147483648;
	i = 0;
	while (++i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value > max_int || value < min_int)
			return (-1);
		tmp = create_node(value);
		if (i == 1)
			*mem->stack_a = tmp;
		else
			push_back_node(mem->stack_a, tmp);
	}
	mem_cont(mem);
	return (0);
}
