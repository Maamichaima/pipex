/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:21:51 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/19 03:41:08 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int c, char **v, char **env)
{
	//(void) c;
	int		i;
	t_data	data;
	t_cmd	cmd;

	if (c == 5)
	{
		inisialiser(&data, v, env, c);
		uni_multi_pipe(data, &cmd);
		i = 0;
		while (i < data.num_cmd - 1)
		{
			close(data.pipe[i][0]);
			close(data.pipe[i][1]);
			i++;
		}
		while (i >= 0)
		{
			wait(NULL);
			i--;
		}
	}
	// char *str;
	// str = correct_path(ft_split(path_in_env(env), ":"), v[1]);
	// printf("%s\n", str);
	// printf("%d\n", access(str, F_OK));
	// execve(str,v + 1, env);
	// printf("error");
	return (0);
}
