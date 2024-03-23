/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:26:00 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/23 00:31:25 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	d;
// 	size_t	s;

// 	i = 0;
// 	s = ft_strlen(src);
// 	if (dstsize == 0 || dstsize <= ft_strlen(dst))
// 		return (s + dstsize);
// 	d = ft_strlen(dst);
// 	j = d;
// 	while (src[i] != '\0' && i < dstsize - d - 1)
// 	{
// 		dst[j] = src[i];
// 		i++;
// 		j++;
// 	}
// 	dst[j] = '\0';
// 	return (d + s);
// }

char	*ft_strjoin_(char *s1, char *s2)
{
	int		ls1;
	int		ls2;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		return (ft_strdup(s2));
	}
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	p = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!p)
		return (NULL);
	p[0] = '\0';
	ft_strlcat(p, s1, ls1 + 1);
	ft_strlcat(p, s2, ls1 + ls2 + 1);
	free(s1);
	return (p);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*str;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = ft_strlen(s1);
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_strchr(char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i] != (char)c && s[i] != '\0')
// 		i++;
// 	if (s[i] == (char)c)
// 		return (&s[i]);
// 	return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }
