/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:04:56 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/19 03:50:26 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// FIN LPATH LI SHIH
char	*correct_path(char **path, char *str)
{
	int		i;
	char	*tmp;

	tmp = str;
	i = 0;
	// printf("%p\n", str);
	if(!str)
		return (str);
	str = ft_strjoin("/", str);
	//printf("%s", str);
	while (path && path[i])
	{
		path[i] = ft_strjoin(path[i], str);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		i++;
	}
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

// ligne of path
char	*path_in_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}
