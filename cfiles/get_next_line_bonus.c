/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:51:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/08 18:00:46 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*left[MAX_FD];
	char		*current_read;
	int			check;

	if (fd < 0 || fd >= MAX_FD || !BUFFER_SIZE)
		return (NULL);
	check = 1;
	while (check > 0 && !ft_strchr(left[fd], '\n'))
	{
		current_read = ft_buffer_alloc();
		if (!current_read)
			return (ft_free_all(&current_read, &left[fd]));
		check = read(fd, current_read, BUFFER_SIZE);
		if (check == -1)
			return (ft_free_all(&current_read, &left[fd]));
		left[fd] = ft_join_leftovers(current_read, &left[fd]);
		free(current_read);
		if (!left[fd])
			return (NULL);
	}
	if (ft_len(left[fd], '\n') < 0 || \
		ft_len(left[fd], '\n') == ft_len(left[fd], '\0'))
		return (ft_line_no_leftovers(&left[fd]));
	else
		return (ft_sep_buffer(&left[fd]));
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
	ssize_t	i;

	current_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!current_read)
		return (NULL);
	i = -1;
	while (++i <= BUFFER_SIZE)
		current_read[i] = '\0';
	return (current_read);
}
