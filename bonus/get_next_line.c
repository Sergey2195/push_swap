/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:16:19 by iannmari          #+#    #+#             */
/*   Updated: 2022/02/15 15:00:04 by iannmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_find(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_withn(char **line, int k, char **ret)
{
	char	*tmp;

	*ret = ft_substr(*line, 0, (size_t)k + 1);
	tmp = ft_substr(*line, k + 1, ft_strlen(*line));
	free(*line);
	*line = tmp;
	if ((*line)[0] == '\0')
	{
		free(*line);
		*line = NULL;
	}
}

char	*ft_cut(char **line, int c)
{
	char	*ret;
	int		k;

	if (c == 0 && *line == NULL)
		return (NULL);
	k = ft_find(*line);
	if (k != -1)
		ft_withn(line, k, &ret);
	else
	{
		ret = ft_strdup(*line);
		free(*line);
		*line = NULL;
	}
	return (ret);
}

int	ft_writestr(char **line, char **buff, int fd)
{
	int		c;
	char	*temp;
	int		k;

	c = read(fd, *buff, BUFFER_SIZE);
	(*buff)[c] = '\0';
	while (c > 0)
	{
		if (*line == NULL)
			*line = ft_strdup(*buff);
		else
		{
			temp = ft_strjoin(*line, *buff);
			free(*line);
			*line = temp;
		}
		k = ft_find(*line);
		if (k != -1)
			break ;
		c = read(fd, *buff, BUFFER_SIZE);
		(*buff)[c] = '\0';
	}
	free(*buff);
	return (c);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	int			c;
	char		*ret;

	if (fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	c = ft_writestr(&line, &buff, fd);
	if (c < 0)
	{
		free(line);
		return (NULL);
	}
	ret = ft_cut(&line, c);
	return (ret);
}
