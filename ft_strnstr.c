/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:41:43 by iannmari          #+#    #+#             */
/*   Updated: 2022/01/19 16:07:02 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find(char *tab1, char *tab2)
{
	int	i;

	i = 0;
	while (tab2[i] != '\0')
	{
		if (tab1[i] == tab2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	z;
	int	k;

	i = 0;
	z = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (haystack[i] && i < (int)len - (int)ft_strlen(needle) + 1)
	{
		if (haystack[i] == needle[k])
		{
			z = ft_find((char *)haystack + i, (char *)needle + k);
			if (z == 0)
				i++;
			else
				return ((char *)(haystack + i));
		}	
		else
			i++;
	}
	return (NULL);
}
