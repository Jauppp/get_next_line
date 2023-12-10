/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:14:01 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/08 17:13:37 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		*current_read;
	int			check;

	if (fd < 0 || fd >= MAX_FD || !BUFFER_SIZE)
		return (NULL);
	check = 1;
	current_read = NULL;
	while (check > 0 && !ft_strchr(left, '\n'))
	{
		current_read = ft_buffer_alloc();
		if (!current_read)
			return (ft_free_all(&current_read, &left));
		check = read(fd, current_read, BUFFER_SIZE);
		if (check == -1)
			return (ft_free_all(&current_read, &left));
		left = ft_join_leftovers(current_read, &left);
		free(current_read);
		if (!left)
			return (NULL);
	}
	if (ft_len(left, '\n') < 0 || ft_len(left, '\n') == ft_len(left, '\0'))
		return (ft_line_no_leftovers(&left));
	else
		return (ft_sep_buffer(&left));
}

char	*ft_join_leftovers(char *current_read, char **left)
{
	char	*temp;

	temp = ft_strjoin(*left, current_read);
	if (!temp)
		return (ft_free_all(NULL, left));
	if (*left)
		ft_free_all(NULL, left);
	*left = ft_substr(temp, 0, ft_len(temp, '\0'));
	if (!*left)
		return (ft_free_all(NULL, &temp));
	free(temp);
	return (*left);
}

char	*ft_sep_buffer(char **left)
{
	char	*line;
	char	*temp;

	line = ft_substr(*left, 0, ft_len(*left, '\n'));
	if (!line)
		return (ft_free_all(NULL, left));
	temp = ft_substr(*left, ft_len(*left, '\n'), BUFFER_SIZE);
	ft_free_all(NULL, left);
	if (!temp)
		return (ft_free_all(&line, NULL));
	*left = ft_substr(temp, 0, ft_len(temp, '\0'));
	if (!(*left))
		return (ft_free_all(&line, &temp));
	if (*left && !*left[0])
		ft_free_all(NULL, left);
	free(temp);
	return (line);
}

char	*ft_line_no_leftovers(char **left)
{
	char	*line;

	line = ft_substr(*left, 0, ft_len(*left, '\0'));
	ft_free_all(NULL, left);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_buffer_alloc(void)
{
	char	*current_read;
	size_t	i;

	current_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!current_read)
		return (NULL);
	i = -1;
	while (++i <= BUFFER_SIZE)
		current_read[i] = '\0';
	return (current_read);
}
