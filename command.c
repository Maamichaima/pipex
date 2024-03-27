/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:15:03 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/27 23:29:35 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executer(t_cmd cmd, t_data data)
{
	int	i;

	dup2(cmd.in, 0);
	dup2(cmd.out, 1);
	close(cmd.in);
	close(cmd.out);
	i = 0;
	while (i < data.num_cmd - 1)
	{
		close(data.pipe[i][0]);
		close(data.pipe[i][1]);
		i++;
	}
	execve(cmd.path, cmd.cmd, data.env);
	write(2, cmd.cmd[0], ft_strlen(cmd.cmd[0]));
	write(2, ": command not found\n", 21);
	ft_fr_char(cmd.cmd);
	if (cmd.env)
		ft_fr_char(cmd.env);
	clear(data);
	exit(127);
}

void	redirections_of_1cmd(t_data data, t_cmd *n)
{
	n->in = open(data.in, O_RDONLY);
	if (n->in == -1)
	{
		clear(data);
		perror(data.in);
		exit(1);
	}
	n->out = data.pipe[0][1];
}

void	redirections_of_2cmd(t_data data, t_cmd *n, int index)
{
	n->out = open(data.out, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (n->out == -1)
	{
		clear(data);
		perror(data.out);
		exit(1);
	}
	n->in = data.pipe[index - 1][0];
}

void	creer_cmd(t_data data, t_cmd *n, int index)
{
	if (index == 0)
		redirections_of_1cmd(data, n);
	else if (index == (data.num_cmd - 1))
		redirections_of_2cmd(data, n, index);
	else
	{
		n->in = data.pipe[index - 1][0];
		n->out = data.pipe[index][1];
	}
	n->env = ft_split(path_in_env(data.env), ":");
	n->cmd = ft_split(data.v[index + 2], "\n\r\f \t\v");
	n->path = correct_path(n->env, n->cmd[0]);
}

void	uni_multi_pipe(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < data->num_cmd)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
		{
			creer_cmd(*data, cmd, i);
			executer(*cmd, *data);
		}
		i++;
	}
}
