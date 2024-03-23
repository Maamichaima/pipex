/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:25:58 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/23 00:31:45 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*stt(int fd, char *str)
{
	char	*buf;
	int		i;

	i = 1;
	buf = malloc((size_t)(BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		str = ft_strjoin_(str, buf);
		if (!str)
			return (NULL);
	}
	free(buf);
	return (str);
}

char	*line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		s[j++] = str[i++];
	if (str[i] == '\n')
	{
		s[j] = '\n';
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*reste(char *str)
{
	char	*s;
	int		j;
	size_t	i;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n' || str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = stt(fd, str);
	if (!str)
		return (NULL);
	s = line(str);
	str = reste(str);
	return (s);
}
