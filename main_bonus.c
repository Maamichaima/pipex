/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:21:51 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/26 01:43:41 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_wait(t_data data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data.num_cmd - 1)
	{
		close(data.pipe[i][0]);
		close(data.pipe[i][1]);
		i++;
	}
	i = 0;
	while (i < data.num_cmd)
	{
		waitpid(data.pids[i], &status, 0);
		i++;
	}
	khwi(data);
	return (status >> 8);
}

int	main(int c, char **v, char **env)
{
	t_data	data;
	t_cmd	cmd;

	cmd.env = env;
	if (c == 6 && (ft_strcmp(v[1], "here_doc") == 0))
	{
		v++;
		inisialiser(&data, v, env, c - 1);
		here_doc(data, cmd, v[1]);
		return (close_wait(data));
	}
	else if (c >= 5)
	{
		inisialiser(&data, v, env, c);
		uni_multi_pipe(&data, &cmd);
		return (close_wait(data));
	}
}
