/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:03:21 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 18:14:47 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char*s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (ss1[i] != ss2[i] || ss1[i] == 0 || ss2[i] == 0)
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

int	do_opers(t_mem *mem, char *oper)
{
	if (ft_strncmp(oper, "sa\n", 5) == 0)
		b_sa(mem);
	else if (ft_strncmp(oper, "sb\n", 5) == 0)
		b_sb(mem);
	else if (ft_strncmp(oper, "ss\n", 5) == 0)
		b_ss(mem);
	else if (ft_strncmp(oper, "pa\n", 5) == 0)
		b_pa(mem);
	else if (ft_strncmp(oper, "pb\n", 5) == 0)
		b_pb(mem);
	else if (ft_strncmp(oper, "ra\n", 5) == 0)
		b_ra(mem);
	else if (ft_strncmp(oper, "rb\n", 5) == 0)
		b_rb(mem);
	else if (ft_strncmp(oper, "rra\n", 5) == 0)
		b_rra(mem);
	else if (ft_strncmp(oper, "rrb\n", 5) == 0)
		b_rrb(mem);
	else if (ft_strncmp(oper, "rr\n", 5) == 0)
		b_rr(mem);
	else if (ft_strncmp(oper, "rrr\n", 5) == 0)
		b_rrr(mem);
	else
		return (1);
	return (0);
}

void	get_opers(t_mem *mem)
{
	char	*oper;

	while (1)
	{
		oper = get_next_line(0);
		if (oper == NULL)
		{
			if (sort_check(mem->stack_a) == -1 && \
			stack_size(mem->stack_b) == 0)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			break ;
		}
		if (do_opers(mem, oper))
		{
			write(1, "Error\n", 6);
			free(oper);
			return ;
		}
		free(oper);
	}
}

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
	if (create_first_lstack(mem, argc, argv) == -1 \
	|| args_check(argv, mem->stack_a) == -1)
		error_exit(mem);
	get_opers(mem);
	free_all(mem);
	return (0);
}