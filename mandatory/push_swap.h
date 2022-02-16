/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:59:29 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 16:39:52 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_lstack{
	int					number;
	int					order;
	int					flag;
	struct s_lstack		*next;
	struct s_lstack		*prev;
}	t_lstack;

typedef struct s_mem{
	t_lstack	**stack_a;
	t_lstack	**stack_b;
	int			max_order;
	int			mid_order;
	int			steps;
}	t_mem;

int			create_first_lstack(t_mem *mem, int argc, char **argv);
void		free_all(t_mem *mem);
void		mini_sorting(t_mem *mem, int argc);
void		error_exit(t_mem *mem);
void		check_args(int argc, char **argv, t_mem *mem);
long long	ft_atoi(const char *str);
int			args_check(char **argv, t_lstack **stack);
int			stack_size(t_lstack **stack);
void		make_orders(t_lstack **stack);
int			sort_check(t_lstack **stack);
t_lstack	*take_last_node(t_lstack **stack);
void		sorting(t_mem *mem);
void		swap(t_lstack **stack);
void		push(t_lstack **from_stack, t_lstack **to_stack);
void		rotate(t_lstack **stack);
void		reverse_rotate(t_lstack **stack);
void		sa(t_mem *mem);
void		sb(t_mem *mem);
void		ss(t_mem *mem);
void		rra(t_mem *mem);
void		rrb(t_mem *mem);
void		pa(t_mem *mem);
void		pb(t_mem *mem);
void		rrr(t_mem *mem);
void		ra(t_mem *mem);
void		rb(t_mem *mem);
void		rr(t_mem *mem);
int			steps_to_top_b(t_mem *mem, t_lstack *node);
int			steps_to_closest_a(t_mem *mem, t_lstack *node);
void		push_min_flag(t_mem *mem);
void		last_rotate(t_mem *mem);
void		sorting_between_four_six(t_mem *mem);
void		sorting_three_numbers_b(t_mem *mem);
void		sorting_three_numbers_a(t_mem *mem);
#endif