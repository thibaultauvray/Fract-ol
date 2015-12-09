/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 18:01:13 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/31 19:10:40 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_n(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_frontend(char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	i++;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(buf))))
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\0')
	{
		str[j++] = buf[i++];
	}
	str[j] = '\0';
	return (str);
}

static char	*ft_backend(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_strlen(buf) == 0)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(buf))))
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_tmp(int i, char *s1, char **line)
{
	if (i == 0)
	{
		*line = ft_backend(s1);
		s1 = ft_frontend(s1);
	}
	else
	{
		*line = ft_backend(s1);
		free(s1);
		s1 = NULL;
	}
	return (s1);
}

int			get_next_line(int const fd, char **line)
{
	t_gnl			b;
	static char		*tmp = NULL;

	if (line == NULL || fd < 0)
		return (-1);
	while ((((b.ret = read(fd, b.buf, BUFF_SIZE))) > 0) || tmp != NULL)
	{
		b.buf[b.ret] = '\0';
		tmp = ft_strjoin(tmp, b.buf);
		if (ft_find_n(tmp) != -1)
		{
			tmp = ft_tmp(0, tmp, line);
			return (1);
		}
		else if (ft_strlen(b.buf) == 0)
		{
			tmp = ft_tmp(42, tmp, line);
			return (0);
		}
	}
	if (b.ret < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}
