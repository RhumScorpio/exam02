/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:31:00 by clesaffr          #+#    #+#             */
/*   Updated: 2023/03/30 02:31:03 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!src)
		return (NULL);
	tmp = malloc(sizeof(char) * (n + 1));
	if (!tmp)
		return (0);
	while (*(src + i) != '\0' && i < n)
	{
		tmp[i] = src[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = 0;
	return (s1);
}

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	while (*(src + len) != '\0')
		++len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*(src + i) != '\0')
	{
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		ret = ft_strdup(s1);
	else if (!s1 && s2)
		ret = ft_strdup(s2);
	else
	{
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!ret)
			return (NULL);
		ret = ft_strcpy(ret, s1);
		ret = ft_strcat(ret, s2);
	}
	return (ret);
}

static int	line_copy(char **line, t_all *a)
{
	int	i;

	i = 0;
	while (a->str[i] && a->str[i] != '\n')
		i++;
	*line = ft_strndup(a->str, i);
	return (i + 1);
}

static int	append_readtostr(int fd, t_all *a)
{
	char	buff[BUFFER_SIZE + 1];
	int		end;
	char	*tmp;

	end = read(fd, buff, BUFFER_SIZE);
	buff[end] = '\0';
	tmp = a->str;
	a->str = ft_gnlstrjoin(a->str, buff);
	if (tmp)
		free(tmp);
	return (end);
}

int	gnl_read(int fd, t_all *a, char **line)
{
	int		backlashed;
	int		end;
	int		foo;

	backlashed = 0;
	end = 1;
	while (end > 0)
	{
		end = append_readtostr(fd, a);
		backlashed = ft_strchr(a->str, '\n');
		if (backlashed >= 0)
			break ;
	}
	foo = line_copy(line, a);
	if (backlashed == -1)
		return (0);
	else
		return (foo);
}

void	change_memorystring(t_all *a, int end)
{
	char	*tmp;

	tmp = a->str;
	if (tmp[end] != '\0')
		a->str = ft_strdup(a->str + end);
	else
		a->str = NULL;
	if (tmp)
		free(tmp);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_all	all;
	int				end;
	char			test[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, test, 0) == -1)
		return (NULL);
	end = gnl_read(fd, &all, &line);
	change_memorystring(&all, end);
	if (end == 0)
		return (NULL);
	return (line);
}

int main(int ac, char **av)
{
	char *str;
	int fd;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((str = get_next_line(fd)))
		{
			printf("%s\n", str);
			free(str);
		}
	}
	return (0);
}
