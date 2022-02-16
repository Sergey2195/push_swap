/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:45:41 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 15:00:23 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		sz;
	char	*pi;

	pi = NULL;
	i = 0;
	sz = (int)ft_strlen((char *)s1);
	pi = malloc(sz + 1);
	if (NULL == pi)
		return (NULL);
	while (s1[i])
	{
		*(pi + i) = *(s1 + i);
		i++;
	}
	*(pi + i) = '\0';
	return (pi);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		j;
	int		i;
	int		v;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	v = ft_strlen(s1) + ft_strlen(s2);
	if (v == 0)
		v = 2;
	res = (char *)malloc(sizeof(char) * (v + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
	{
		res[i] = s1[i];
	}
	while (s2[++j])
		res[i++] = s2[j];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
	{
		res = (char *)malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) >= len)
		res = (char *)malloc(sizeof(char) * len + 1);
	else
		res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
