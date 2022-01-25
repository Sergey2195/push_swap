/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:27:00 by iannmari          #+#    #+#             */
/*   Updated: 2022/01/25 18:42:07 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(int *tab)
{
	free(tab);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_repeats(int *tab, int i)
{
	int	k;
	int	num;
	int	z;

	k = 0;
	while (k <= i)
	{
		z = k + 1;
		num = tab[k];
		while (z <= i)
		{
			if (num == tab[z])
				return (-1);
			z++;
		}
		k++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int	i;
	int	*tab;
	int	num;

	i = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	tab = (int *)malloc(sizeof(int) * argc);
	if (tab == NULL)
		ft_error(tab);
	while (i < argc - 1)
	{
		num = ft_atoi(argv[i + 1]);
		if (num == 0)
			if (ft_strnstr("0", argv[i + 1], ft_strlen(argv[i + 1])) == NULL)
				ft_error(tab);
		tab[i] = num;
		i++;
	}
	if (ft_repeats(tab, i) == -1)
		ft_error(tab);
	free(tab);
}

int	*write_sorted(int *tab, int i)
{
	int	k;
	int	*sorted_mass;

	sorted_mass = (int *)malloc(sizeof(int) * i);
	if (!sorted_mass)
		return (NULL);
	k = 0;
	while (k < i)
	{
		sorted_mass[k] = tab[k];
		k++;
	}
	return (sorted_mass);
}

int	*ft_sort(int *tab, int i)
{
	int	k;
	int	j;
	int	tmp;
	int	*sorted_mass;

	j = 1;
	while (j < i)
	{
		k = j;
		while (k > 0 && tab[k - 1] > tab[k])
		{
			tmp = tab[k - 1];
			tab[k - 1] = tab[k];
			tab[k] = tmp;
			k--;
		}
		j++;
	}
	sorted_mass = write_sorted(tab, i);
	return (sorted_mass);
}
t_struct *get_new_node(int	i)
{
	t_struct	*p;

	p = malloc(sizeof(t_struct));
	p->flag = 0;
	p->value = i;
	p->next = NULL;
	p->order = -1;
	return (p);
}

void	init_struct(int *mass, int *sorted_mass, int i, t_rep *rep)
{
	t_struct	*p;
	int			j;

	j = 0;
	while (j < i)
	{
		p = get_new_node(mass[j]);
	}
}

void	init_info(int argc, t_info *info, char **argv)
{
	int	*mass1;
	int	j;
	
	j = 0;
	info->i = 0;
	info->mass = (int *)malloc(sizeof(int) * argc);
	mass1 = (int *)malloc(sizeof(int) * argc);
	info->sorted_mass = (int *)malloc(sizeof(int) * argc);
	while (info->i < argc - 1)
	{
		info->mass[info->i] = ft_atoi(argv[info->i + 1]);
		info->i += 1;
	}
	while (j < info->i)
	{
		mass1[j] = info->mass[j];
		j++;
	}
	info->sorted_mass = ft_sort(mass1, info->i);
	free(mass1);
}

int	malloc_vars(t_rep **rep, t_struct **stack_a, t_struct **stack_b, t_info **info)
{
	*rep = malloc(sizeof(t_rep));
	*stack_a = malloc(sizeof(stack_a));
	*stack_b = malloc(sizeof(stack_b));
	*info = malloc(sizeof(t_info));
	if (!*rep || !*stack_a || !*stack_b || !*info)
		return (-1);
	else
		return (0);
}

t_struct	*create_node(t_info *info, int unsorted_ind)
{
	t_struct *node;
	int		k;

	k = 0;
	node = (t_struct *)malloc(sizeof(t_struct));
	node->value = info->mass[unsorted_ind];
	while (1)
	{
		if (node->value == info->sorted_mass[k])
			break ;
		k++;
	}
	node->order = k;
	node->next = NULL;
	return (node);
}

void	ft_init_first_a(t_struct **stack_a, t_info *info)
{
	int	i;
	t_struct *tmp;

	i = 0;
	tmp = malloc(sizeof(t_struct));
	while (i < info->i)
	{
		tmp = create_node(info, i);
		tmp->next = *stack_a;
		*stack_a = tmp;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_rep		*rep;
	t_struct	*stack_a;
	t_struct	*stack_b;
	t_info		*info;
	// int			i;
	
	if (malloc_vars(&rep, &stack_a, &stack_b, &info) == -1)
		return (-1);
	check_args(argc, argv);
	init_info(argc, info, argv);
	ft_init_first_a(&stack_a, info);
	int i = 0;
	while (i < info->i)
	{
		printf("%d order %d\n", stack_a->value, stack_a->order);
		stack_a = stack_a -> next;
		i++;
	}
	
	
}
