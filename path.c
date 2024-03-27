/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:04:56 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/26 16:20:21 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

// FIN LPATH LI SHIH
char	*correct_path(char **path, char *str)
{
	int		i;
	char	*tmp;
	char	*cmd;

	tmp = str;
	i = 0;
	if (!str)
		return (str);
	if (ft_strchr(str, '/'))
		return (tmp);
	str = ft_strjoin("/", str);
	while (path && path[i])
	{
		cmd = ft_strjoin(path[i], str);
		if (access(cmd, F_OK) == 0)
		{
			free(str);
			return (cmd);
		}
		free(cmd);
		i++;
	}
	free(str);
	return (tmp);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*path_in_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
