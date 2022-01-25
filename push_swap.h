/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:27:04 by iannmari          #+#    #+#             */
/*   Updated: 2022/01/21 16:51:37 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_struct{
	int				value;
	int				order;
	int				flag;
	struct s_struct	*next;
}	t_struct;

typedef struct s_info{
	int	*mass;
	int	*sorted_mass;
	int	i;
}		t_info;

typedef struct s_rep{
	t_struct	**stack_a;
	t_struct	**stack_b;
	int			min;
	int			max;
	int			med;
	}	t_rep;

long int	ft_atoi(const char *str);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlen(const char *str);
#endif