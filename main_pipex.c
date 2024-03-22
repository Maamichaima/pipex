/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:21:51 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/22 20:20:22 by cmaami           ###   ########.fr       */
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
		waitpid(data.pids[i], &status, WCONTINUED);
		i++;
	}
	return (WEXITSTATUS(status));
}

int	main(int c, char **v, char **env)
{
	t_data	data;
	t_cmd	cmd;

	if (c == 5)
	{
		inisialiser(&data, v, env, c);
		uni_multi_pipe(&data, &cmd);
		return (close_wait(data));
	}
	return (0);
}
