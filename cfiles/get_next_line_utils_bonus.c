/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:59:17 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/08 18:11:55 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
	}
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_free_all(char **current_read, char **left)
{
	if (current_read && *current_read)
	{
		free (*current_read);
		*current_read = NULL;
	}
	if (left && *left)
	{
		free(*left);
		*left = NULL;
	}
	return (NULL);
}

ssize_t	ft_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (c == '\n')
	{
		while (s && s[i])
		{
			if (s[i] == '\n')
				return (i + 1);
			i++;
		}
		return (-1);
	}
	else
	{
		while (s && s[i])
			i++;
		return (i);
	}
}

char	*ft_substr(char const *s, unsigned int start, ssize_t len)
{
	ssize_t	i;
	ssize_t	sub_len;
	char	*substr;

	i = 0;
	if (!s || !len || !s[i])
		return (NULL);
	if (start >= ft_len(s, '\0'))
		return (NULL);
	sub_len = ft_len(s, '\0') - start;
	if (sub_len > len)
		sub_len = len;
	substr = malloc(sub_len + 1 * sizeof(char));
	if (!substr)
		return (NULL);
	substr[sub_len] = '\0';
	while (s[start] && i < len)
		substr[i++] = s[start++];
	return (substr);
}

char	*ft_strjoin(char *g_leftovers, char *read)
{
	size_t		strjoin_len;
	size_t		i;
	size_t		j;
	char		*strjoin;

	if (!g_leftovers)
		return (ft_substr(read, 0, BUFFER_SIZE + 1));
	if (!read)
		return (NULL);
	strjoin_len = ft_len(g_leftovers, '\0') + ft_len(read, '\0');
	strjoin = malloc(strjoin_len + 1 * sizeof (char));
	if (!strjoin)
		return (NULL);
	strjoin[strjoin_len] = '\0';
	i = 0;
	j = 0;
	while (g_leftovers[j])
		strjoin[i++] = g_leftovers[j++];
	j = 0;
	while (read[j])
		strjoin[i++] = read[j++];
	return (strjoin);
}
