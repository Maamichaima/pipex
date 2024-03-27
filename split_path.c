/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:20:33 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/26 18:23:19 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_word(char *s, char *charset)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && check_sep(s[i], charset))
			i++;
		if (s[i] != '\0')
			w++;
		while (s[i] != '\0' && !check_sep(s[i], charset))
			i++;
	}
	return (w);
}

int	c_char(char *str, char *charset)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i] != '\0' && !check_sep(str[i], charset))
	{
		c++;
		i++;
	}
	return (c);
}

static char	*alloc_word(char *s, char *c)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * (c_char(s, c) + 1));
	if (!p)
		return (NULL);
	while (s[i] && !check_sep(s[i], c))
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		w;

	w = 0;
	i = 0;
	if (!str || !charset)
		return (NULL);
	split = (char **)malloc(sizeof(char **) * (count_word(str, charset) + 1));
	if (!split)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			split[w] = alloc_word(str + i, charset);
			w++;
		}
		while (str[i] != '\0' && !check_sep(str[i], charset))
			i++;
	}
	split[w] = 0;
	return (split);
}
