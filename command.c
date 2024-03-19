/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:15:03 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/19 03:53:17 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executer(t_cmd cmd, t_data data)
{
	int	i;

	dup2(cmd.in, 0);
	dup2(cmd.out, 1);
	i = 0;
	while (i < data.num_cmd - 1)
	{
		close(data.pipe[i][0]);
		close(data.pipe[i][1]);
		i++;
	}
	execve(cmd.path, cmd.cmd, cmd.env);
	write(2, "eroooor cmd \n", 15);
	exit(0);
}

void	infile(t_data data, t_cmd *n)
{
	n->in = open(data.in, O_RDONLY);
	if (n->in == -1)
	{
		perror(data.in);
		exit(1);
	}
	n->out = data.pipe[0][1];
}

void	outfile(t_data data, t_cmd *n, int index)
{
	n->out = open(data.out, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (n->in == -1)
	{
		perror(data.in);
		exit(1);
	}
	n->in = data.pipe[index - 1][0];
}

void	creer_cmd(t_data data, t_cmd *n, int index)
{
	n->cmd = ft_split(data.v[index + 2], "\n \t");
	n->path = correct_path(ft_split(path_in_env(data.env), ":"), n->cmd[0]);
	//printf("h%sh\n", n->path);
	// if (n->path == NULL)
	// 	exit(1);
	n->env = data.env;
	if (index == 0)
		infile(data, n);
	else if (index == (data.num_cmd - 1))
		outfile(data, n, index);
	else
	{
		n->in = data.pipe[index - 1][0];
		n->out = data.pipe[index][1];
	}
}

void	uni_multi_pipe(t_data data, t_cmd *cmd)
{
	int	i;
	int	pid;

	i = 0;
	while (i < data.num_cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			creer_cmd(data, cmd, i);
			executer(*cmd, data);
		}
		i++;
	}
}
