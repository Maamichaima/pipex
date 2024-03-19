/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:17:35 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/12 00:19:38 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_is_mot(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
