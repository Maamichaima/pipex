/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:15:03 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/23 00:39:31 by cmaami           ###   ########.fr       */
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
	execve(cmd.path, cmd.cmd, cmd.env);
	//ft_free(i,data.pipe);
	//free(cmd.path);
	ft_fr(i, cmd.cmd);
	khwi(data);
	write(2, "eroooor cmd", 15);
	exit(127);
}

void	infile(t_data data, t_cmd *n)
{
	n->in = open(data.in, O_RDONLY);
	if (n->in == -1)
	{
		//ft_free(1,data.pipe);
		perror(data.in);
		exit(1);
	}
	n->out = data.pipe[0][1];
}

void	outfile(t_data data, t_cmd *n, int index)
{
	n->out = open(data.out, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (n->out == -1)
	{
		perror(data.out);
		exit(1);
	}
	n->in = data.pipe[index - 1][0];
}

void	creer_cmd(t_data data, t_cmd *n, int index)
{
	// printf("h%sh\n", n->path);
	// if (n->path == NULL)
	// 	exit(1);
	if (index == 0)
		infile(data, n);
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
