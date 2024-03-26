/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:52:26 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/26 01:41:26 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	in_here_doc(t_data data, t_cmd *n, int *pipe_her)
{
	n->in = pipe_her[0];
	if (n->in == -1)
	{
		khwi(data);
		perror(data.in);
		exit(1);
	}
	n->out = data.pipe[0][1];
}

void	creer_cmd_here(t_data data, t_cmd *n, int index, int *pipe_her)
{
	if (index == 0)
		in_here_doc(data, n, pipe_her);
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

void	pipe_here_doc(t_data data, t_cmd *cmd, int *pipe_her)
{
	int	i;
	int	pid;

	i = 0;
	while (i < data.num_cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			creer_cmd_here(data, cmd, i, pipe_her);
			executer(*cmd, data);
		}
		i++;
	}
}

void	ppp(int *pipe_her, t_data data, t_cmd *cmd)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		dup2(pipe_her[0], 0);
		close(pipe_her[0]);
		pipe_here_doc(data, cmd, pipe_her);
		// exit(0);
	}
	else
	{
		close(pipe_her[0]);
		waitpid(pid, &status, 0);
		// return (WEXITSTATUS(status));
	}
}

void	here_doc(t_data data, t_cmd cmd, char *limiter)
{
	char	*tmp;
	char	*lim;
	int		pipe_her[2];

	pipe(pipe_her);
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
		write(pipe_her[1], tmp, ft_strlen(tmp));
		free(tmp);
	}
	free(lim);
	close(pipe_her[1]);
	ppp(pipe_her, data, &cmd);
	// return (close_wait(data));
}
