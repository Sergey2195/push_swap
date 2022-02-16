/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:04:28 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 17:49:00 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../mandatory/push_swap.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	b_sa(t_mem *mem);
void	b_sb(t_mem *mem);
void	b_ss(t_mem *mem);
void	b_pa(t_mem *mem);
void	b_pb(t_mem *mem);
void	b_rra(t_mem *mem);
void	b_rrb(t_mem *mem);
void	b_rrr(t_mem *mem);
void	b_ra(t_mem *mem);
void	b_rb(t_mem *mem);
void	b_rr(t_mem *mem);
# endif
#endif
