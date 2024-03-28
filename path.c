/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:04:56 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/28 22:28:52 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*correct_path(char **path, char *str)
{
	int		i;
	char	*tmp;
	char	*cmd;

	tmp = str;
	i = 0;
	if (!str)
		return (str);
	if (ft_strchr(str, '/') || !path)
		return (str);
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
	return (NULL);
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

void	message_error(t_cmd cmd, t_data data)
{
	if (ft_strchr(cmd.cmd[0], '/'))
	{
		if (access(cmd.cmd[0], F_OK) == -1)
		{
			perror(cmd.cmd[0]);
			ft_fr_char(cmd.cmd);
			ft_fr_char(cmd.env);
			clear(data);
			exit(127);
		}
		if (access(cmd.cmd[0], X_OK) == -1)
		{
			perror(cmd.cmd[0]);
			ft_fr_char(cmd.cmd);
			ft_fr_char(cmd.env);
			clear(data);
			exit(126);
		}
	}
	write(2, cmd.cmd[0], ft_strlen(cmd.cmd[0]));
	write(2, ": command not found\n", 21);
	ft_fr_char(cmd.cmd);
	ft_fr_char(cmd.env);
	clear(data);
	exit(127);
}
