/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:09:41 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/21 01:58:07 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	inisialiser(t_data *data, char **v, char **env, int c)
{
	int	i;

	i = 0;
	data->v = v;
	data->env = env;
	data->in = v[1];
	data->out = v[c - 1];
	data->num_cmd = c - 3;
	data->pipe = malloc(sizeof(int *) * (data->num_cmd - 1));
	data->pids = malloc(sizeof(int) * data->num_cmd);
	while (i < data->num_cmd - 1)
	{
		data->pipe[i] = malloc(sizeof(int) * 2);
		if (pipe(data->pipe[i]) == -1)
		{
			perror("pip");
			exit(1);
		}
		i++;
	}
}
