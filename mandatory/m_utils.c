/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:44:47 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 15:46:52 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char **argv, t_mem *mem)
{
	if (create_first_lstack(mem, argc, argv) == -1 \
	|| args_check(argv, mem->stack_a) == -1)
		error_exit(mem);
	if (sort_check(mem->stack_a) == -1)
	{
		free_all(mem);
		exit(EXIT_FAILURE);
	}
}

void	error_exit(t_mem *mem)
{
	write(1, "Error\n", 6);
	if (mem == NULL)
		free_all(mem);
	exit(EXIT_FAILURE);
}

void	mini_sorting(t_mem *mem, int argc)
{
	if (argc == 3)
		sa(mem);
	if (argc == 4)
		sorting_three_numbers_a(mem);
	else if (argc > 4)
		sorting_between_four_six(mem);
}

void	free_all(t_mem *mem)
{
	while ((*mem->stack_a)->next)
	{
		(*mem->stack_a) = (*mem->stack_a)->next;
		free((*mem->stack_a)->prev);
	}
	free(*mem->stack_a);
	free(mem);
}