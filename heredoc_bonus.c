/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:52:26 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/23 04:08:22 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	in_here_doc(t_data data, t_cmd *n)
{
	n->in = open("heredoc", O_RDONLY);
	if (n->in == -1)
	{
		khwi(data);
		perror(data.in);
		exit(1);
	}
	n->out = data.pipe[0][1];
}

void	creer_cmd_here(t_data data, t_cmd *n, int index)
{
	if (index == 0)
		in_here_doc(data, n);
	else if (index == (data.num_cmd - 1))
		outfile(data, n, index);
	else
	{
		n->in = data.pipe[index - 1][0];
		n->out = data.pipe[index][1];
	}
	n->env = ft_split(path_in_env(data.env), ":");
	n->cmd = ft_split(data.v[index + 2], "\n\r\f \t");
	n->path = correct_path(n->env, n->cmd[0]);
}

void	pipe_here_doc(t_data data, t_cmd *cmd)
{
	int	i;
	int	pid;

	i = 0;
	while (i < data.num_cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			creer_cmd_here(data, cmd, i);
			executer(*cmd, data);
		}
		i++;
	}
}

void	here_doc(t_data data, t_cmd cmd, char *limiter)
{
	int		fd;
	char	*tmp;
	char *lim;

	fd = open("heredoc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	lim = ft_strjoin(limiter, "\n");
	while (1)
	{
		write(1, "heredoc>", 9);
		tmp = get_next_line(0);
		if (!tmp || ft_strcmp(tmp, lim) == 0)
		{
			free(tmp);
			break ;
		}
		write(fd, tmp, ft_strlen(tmp));
		free(tmp);
	}
	free(lim);
	close(fd);
	pipe_here_doc(data, &cmd);
}
