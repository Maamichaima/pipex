/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:21:30 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/26 02:15:32 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_fr_char(char **t)
{
	int	j;

	j = 0;
	while (t[j])
	{
		free(t[j]);
		j++;
	}
	free(t);
	return (NULL);
}

void	*ft_fr_int(int i, int **t)
{
	while (i > 0)
	{
		free(t[i - 1]);
		i--;
	}
	free(t);
	return (NULL);
}

void	khwi(t_data data)
{
	free(data.pids);
	ft_fr_int(data.num_cmd - 1, data.pipe);
}
