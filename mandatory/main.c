/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:58:43 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/19 15:05:09 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_mem		*mem;
	t_lstack	*stack_a;
	t_lstack	*stack_b;

	mem = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	mem = malloc(sizeof(t_mem));
	if (!mem)
		error_exit(mem);
	mem->stack_a = &stack_a;
	mem->stack_b = &stack_b;
	check_args(argc, argv, mem);
	make_orders(mem->stack_a);
	if (argc <= 7)
		mini_sorting(mem, argc);
	else
		sorting(mem);
	free_all(mem);
	return (0);
}
